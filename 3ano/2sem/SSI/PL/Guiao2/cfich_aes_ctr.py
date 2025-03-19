import os
import sys
from Crypto.Cipher import AES
from Crypto.Util import Counter

def encrypt_file(key, in_filename, out_filename):
    nonce = os.urandom(8)  # 8 bytes para CTR
    ctr = Counter.new(64, prefix=nonce, initial_value=0)
    cipher = AES.new(key, AES.MODE_CTR, counter=ctr)
    with open(in_filename, 'rb') as infile, open(out_filename, 'wb') as outfile:
        outfile.write(nonce)  # guarda o nonce no início
        while True:
            chunk = infile.read(1024)
            if len(chunk) == 0: break
            outfile.write(cipher.encrypt(chunk))

def decrypt_file(key, in_filename, out_filename):
    with open(in_filename, 'rb') as infile:
        nonce = infile.read(8)
        ctr = Counter.new(64, prefix=nonce, initial_value=0)
        cipher = AES.new(key, AES.MODE_CTR, counter=ctr)
        with open(out_filename, 'wb') as outfile:
            while True:
                chunk = infile.read(1024)
                if len(chunk) == 0: break
                outfile.write(cipher.decrypt(chunk))

def main():
    if len(sys.argv) != 5:
        print("Usage: {} <enc/dec> <key> <input_file> <output_file>".format(sys.argv[0]))
        sys.exit(1)
    mode = sys.argv[1]
    key = sys.argv[2].encode('utf-8')
    key = key.ljust(16, b'\0')[:16]  # garante 16 bytes
    in_file = sys.argv[3]
    out_file = sys.argv[4]
    
    if mode == 'enc':
        encrypt_file(key, in_file, out_file)
    elif mode == 'dec':
        decrypt_file(key, in_file, out_file)
    else:
        print("Modo inválido")
        sys.exit(1)

if __name__ == "__main__":
    main()
