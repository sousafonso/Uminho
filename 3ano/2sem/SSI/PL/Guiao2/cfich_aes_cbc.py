import os
import sys
from Crypto.Cipher import AES

def pad(data):
    pad_length = 16 - (len(data) % 16)
    return data + bytes([pad_length]) * pad_length

def unpad(data):
    pad_length = data[-1]
    return data[:-pad_length]

def encrypt_file(key, in_filename, out_filename):
    iv = os.urandom(16)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    with open(in_filename, 'rb') as infile:
        plaintext = infile.read()
    padded_text = pad(plaintext)
    ciphertext = cipher.encrypt(padded_text)
    with open(out_filename, 'wb') as outfile:
        outfile.write(iv)  # IV é escrito no início
        outfile.write(ciphertext)

def decrypt_file(key, in_filename, out_filename):
    with open(in_filename, 'rb') as infile:
        iv = infile.read(16)
        ciphertext = infile.read()
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_text = cipher.decrypt(ciphertext)
    plaintext = unpad(padded_text)
    with open(out_filename, 'wb') as outfile:
        outfile.write(plaintext)

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
