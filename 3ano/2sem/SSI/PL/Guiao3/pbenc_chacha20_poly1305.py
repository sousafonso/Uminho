import os
import argparse
from cryptography.hazmat.primitives.ciphers.aead import ChaCha20Poly1305

def encrypt_file(key_path, input_path, output_path):
    # Lê a chave e valida seu tamanhox
    with open(key_path, 'rb') as kf:
        key = kf.read()
    if len(key) != 32:
        print("Erro: A chave deve ter 32 bytes para ChaCha20Poly1305.")
        return
    # Ler entrada
    with open(input_path, 'rb') as f:
        data = f.read()
    nonce = os.urandom(12)  # nonce de 12 bytes
    chacha = ChaCha20Poly1305(key)
    ciphertext = chacha.encrypt(nonce, data, None)
    # Armazena nonce concatenado com o ciphertext
    with open(output_path, 'wb') as f:
        f.write(nonce + ciphertext)
    print(f"Arquivo encriptado com ChaCha20Poly1305 em: {output_path}")
