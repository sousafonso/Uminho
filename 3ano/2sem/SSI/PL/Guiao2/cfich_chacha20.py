import sys
import os
from Crypto.Cipher import ChaCha20

def usage():
    print("Usage:")
    print("  setup <fkey>")
    print("  enc <fich> <fkey>")
    print("  dec <fich> <fkey>")
    sys.exit(1)

if len(sys.argv) < 3:
    usage()

op = sys.argv[1]

if op == "setup":
    if len(sys.argv) != 3:
        usage()
    key_file = sys.argv[2]
    key = os.urandom(32)  # 256-bit key
    with open(key_file, "wb") as kf:
        kf.write(key)
    print("Key generated and saved to", key_file)

elif op == "enc":
    if len(sys.argv) != 4:
        usage()
    input_file = sys.argv[2]
    key_file = sys.argv[3]
    # Read key
    with open(key_file, "rb") as kf:
        key = kf.read()
    # Read plaintext
    with open(input_file, "rb") as inf:
        plaintext = inf.read()
    # Generate nonce and encrypt
    nonce = os.urandom(8)  # ChaCha20 nonce is 8 bytes
    cipher = ChaCha20.new(key=key, nonce=nonce)
    ciphertext = cipher.encrypt(plaintext)
    # Write nonce and ciphertext to output file
    output_file = input_file + ".enc"
    with open(output_file, "wb") as outf:
        outf.write(nonce + ciphertext)
    print("File encrypted and saved to", output_file)

elif op == "dec":
    if len(sys.argv) != 4:
        usage()
    input_file = sys.argv[2]
    key_file = sys.argv[3]
    # Read key
    with open(key_file, "rb") as kf:
        key = kf.read()
    # Read nonce and ciphertext
    with open(input_file, "rb") as inf:
        data = inf.read()
    nonce = data[:8]
    ciphertext = data[8:]
    cipher = ChaCha20.new(key=key, nonce=nonce)
    plaintext = cipher.decrypt(ciphertext)
    output_file = input_file + ".dec"
    with open(output_file, "wb") as outf:
        outf.write(plaintext)
    print("File decrypted and saved to", output_file)

else:
    usage()
