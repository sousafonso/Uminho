import socket
from cryptography.hazmat.primitives.asymmetric import dh
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import serialization
from cert_utils import *

# Configuração DH
parameters = dh.generate_parameters(generator=2, key_size=2048)
private_key = parameters.generate_private_key()

# Carregar certificado e chave do cliente
with open("VAULT_CLI1.key", "rb") as f:
    client_private_key = serialization.load_pem_private_key(
        f.read(),
        password=None
    )

with open("VAULT_CLI1.crt", "rb") as f:
    client_cert = cert_load(f.read())

# Carregar CA
with open("VAULT_CA.crt", "rb") as f:
    ca_cert = cert_load(f.read())

def main():
    # 1. Enviar g^x para o servidor
    gx_bytes = private_key.public_key().public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    )
    
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect(('localhost', 12345))
        s.send(gx_bytes)
        
        # 2. Receber resposta do servidor
        data = s.recv(4096)
        gy_bytes, rest = unpair(data)
        signature, server_cert_bytes = unpair(rest)
        server_cert = cert_load(server_cert_bytes)
        
        # Validar certificado do servidor
        cert_validtime(server_cert)
        cert_validsubject(server_cert, "BOB")
        server_cert.verify_directly_issued_by(ca_cert)
        
        # Verificar assinatura do servidor
        verify_signature(
            server_cert.public_key(),
            signature,
            gy_bytes + gx_bytes
        )
        
        # Calcular chave compartilhada
        peer_public_key = dh.PublicKey.from_encoded(parameters, gy_bytes)
        shared_key = private_key.exchange(peer_public_key)
        
        # 3. Enviar assinatura e certificado
        client_sig = sign_data(client_private_key, gx_bytes + gy_bytes)
        cert_bytes = client_cert.public_bytes(serialization.Encoding.PEM)
        s.send(mkpair(client_sig, cert_bytes))
        
        # Derivação de chave
        derived_key = HKDF(
            algorithm=hashes.SHA256(),
            length=32,
            salt=None,
            info=b'sts key derivation',
        ).derive(shared_key)
        
        print("Handshake completo! Chave derivada:", derived_key.hex())

if __name__ == "__main__":
    main()