from Crypto.Cipher import AES
from Crypto.Util import Counter
from Crypto.Protocol.KDF import PBKDF2
import os
from Crypto.Hash import HMAC, SHA256
import sys

def encrypt_file(password, in_filename, out_filename):
    # Gerar salt e derivar 32 bytes => 16 bytes para AES, 16 bytes para HMAC
    salt = os.urandom(16)
    key = PBKDF2(password, salt, dkLen=32, count=100000)
    key_enc = key[:16]
    key_mac = key[16:]
    # Gerar IV e configurar o contador para AES CTR
    iv = os.urandom(16)
    ctr = Counter.new(128, initial_value=int.from_bytes(iv, byteorder="big"))
    cipher = AES.new(key_enc, AES.MODE_CTR, counter=ctr)

    with open(in_filename, "rb") as f:
        plaintext = f.read()
    ciphertext = cipher.encrypt(plaintext)
    # Calcular o MAC sobre o ciphertext com HMAC-SHA256
    mac = HMAC.new(key_mac, ciphertext, SHA256).digest()
    # Escrever salt, IV, ciphertext e MAC para o ficheiro de output
    with open(out_filename, "wb") as out:
        out.write(salt)
        out.write(iv)
        out.write(ciphertext)
        out.write(mac)

def usage():
    print("Usage: {} password <input file> <output file>".format(sys.argv[0]))

if __name__ == '__main__':
    if len(sys.argv) != 4:
        usage()
        sys.exit(1)
    password = sys.argv[1]
    in_filename = sys.argv[2]
    out_filename = sys.argv[3]
    encrypt_file(password, in_filename, out_filename)
