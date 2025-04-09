import socket
import os
from cryptography.hazmat.primitives.asymmetric import dh
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import serialization
from cert_utils import *

# Configuração DH
parameters = dh.generate_parameters(generator=2, key_size=2048)
private_key = parameters.generate_private_key()

# Carregar certificado e chave do servidor
with open("server_pub.key", "rb") as f:
    server_private_key = serialization.load_pem_private_key(
        f.read(),
        password=None
    )

with open("VAULT_SERVER.crt", "rb") as f:
    server_cert = cert_load(f.read())

# Carregar CA
with open("VAULT_CA.crt", "rb") as f:
    ca_cert = cert_load(f.read())

def handle_client(conn):
    # 1. Receber g^x do cliente
    gx_bytes = conn.recv(1024)
    peer_public_key = dh.PublicKey.from_encoded(parameters, gx_bytes)
    
    # 2. Gerar g^y e chave compartilhada
    y = private_key.exchange(peer_public_key)
    
    # 3. Preparar resposta: g^y, signature, certificado
    gy_bytes = private_key.public_key().public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    )
    
    # Assinar (gy || gx)
    signature = sign_data(server_private_key, gy_bytes + gx_bytes)
    
    # Empacotar e enviar
    cert_bytes = server_cert.public_bytes(serialization.Encoding.PEM)
    response = mkpair(gy_bytes, mkpair(signature, cert_bytes))
    conn.send(response)
    
    # 4. Receber assinatura e certificado do cliente
    client_data = conn.recv(4096)
    client_sig, client_cert_bytes = unpair(client_data)
    client_cert = cert_load(client_cert_bytes)
    
    # Validar certificado do cliente
    cert_validtime(client_cert)
    cert_validsubject(client_cert, "ALICE")
    client_cert.verify_directly_issued_by(ca_cert)
    
    # Verificar assinatura do cliente
    verify_signature(
        client_cert.public_key(),
        client_sig,
        gx_bytes + gy_bytes
    )
    
    # Derivação de chave
    derived_key = HKDF(
        algorithm=hashes.SHA256(),
        length=32,
        salt=None,
        info=b'sts key derivation',
    ).derive(y)
    
    print("Handshake completo! Chave derivada:", derived_key.hex())
    conn.close()

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(('localhost', 12345))
        s.listen()
        print("Servidor aguardando conexões...")
        conn, addr = s.accept()
        with conn:
            handle_client(conn)

if __name__ == "__main__":
    main()