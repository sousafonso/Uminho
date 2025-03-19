import sys
import getpass
from Crypto.Cipher import ChaCha20
from Crypto.Random import get_random_bytes
from hashlib import pbkdf2_hmac

SALT_SIZE = 16       # Tamanho do salt
NONCE_SIZE = 8       # Tamanho do nonce para ChaCha20
KDF_ITERATIONS = 100000
KEY_LEN = 32         # Tamanho da chave derivada

def derive_key(passphrase, salt):
    return pbkdf2_hmac('sha256', passphrase.encode(), salt, KDF_ITERATIONS, dklen=KEY_LEN)

def encrypt(infile, outfile):
    # Ler ficheiro de entrada
    with open(infile, 'rb') as f:
        plaintext = f.read()
    # Ler pass-phrase do user
    passphrase = getpass.getpass("Enter passphrase: ")
    salt = get_random_bytes(SALT_SIZE)
    key = derive_key(passphrase, salt)
    nonce = get_random_bytes(NONCE_SIZE)
    cipher = ChaCha20.new(key=key, nonce=nonce)
    ciphertext = cipher.encrypt(plaintext)
    # Escrever ficheiro de saída com salt+nonce+ciphertext
    with open(outfile, 'wb') as f:
        f.write(salt + nonce + ciphertext)
    print("Encryption complete.")

def decrypt(infile, outfile):
    # Ler ficheiro cifrado
    with open(infile, 'rb') as f:
        filedata = f.read()
    salt = filedata[:SALT_SIZE]
    nonce = filedata[SALT_SIZE:SALT_SIZE+NONCE_SIZE]
    ciphertext = filedata[SALT_SIZE+NONCE_SIZE:]
    passphrase = getpass.getpass("Enter passphrase: ")
    key = derive_key(passphrase, salt)
    cipher = ChaCha20.new(key=key, nonce=nonce)
    plaintext = cipher.decrypt(ciphertext)
    # Escrever o ficheiro de saída com o plaintext
    with open(outfile, 'wb') as f:
        f.write(plaintext)
    print("Decryption complete.")

def usage():
    print("Usage: {} <enc|dec> <inputfile> <outputfile>".format(sys.argv[0]))

def main():
    if len(sys.argv) != 4:
        usage()
        sys.exit(1)
    mode, infile, outfile = sys.argv[1:]
    if mode == 'enc':
        encrypt(infile, outfile)
    elif mode == 'dec':
        decrypt(infile, outfile)
    else:
        usage()
        sys.exit(1)

if __name__ == "__main__":
    main()
