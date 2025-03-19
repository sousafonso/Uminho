import sys
import os

def usage():
    print("Usage:")
    print("  chacha20_int_attck.py <fctxt> <pos> <ptxtAtPos> <newPtxtAtPos>")
    sys.exit(1)

if len(sys.argv) != 5:
    usage()

fctxt = sys.argv[1]
try:
    pos = int(sys.argv[2])
except ValueError:
    print("Error: pos deve ser um inteiro.")
    sys.exit(1)
ptxt_at_pos = sys.argv[3].encode("utf-8")
new_ptxt_at_pos = sys.argv[4].encode("utf-8")
if len(ptxt_at_pos) != len(new_ptxt_at_pos):
    print("Error: <ptxtAtPos> e <newPtxtAtPos> devem ter o mesmo tamanho.")
    sys.exit(1)

# ...existing code: leitura do ficheiro...
with open(fctxt, "rb") as inf:
    data = inf.read()
nonce = data[:8]
ciphertext = bytearray(data[8:])

# Extrair o fragmento de ciphertext na posição indicada
frag = ciphertext[pos: pos+len(ptxt_at_pos)]
if len(frag) != len(ptxt_at_pos):
    print("Error: posição ou tamanho inválido.")
    sys.exit(1)

# Calcular o keystream usando o plaintext conhecido: ks = frag XOR ptxt_at_pos
ks = bytes([a ^ b for a, b in zip(frag, ptxt_at_pos)])
# Calcular o novo fragmento ciphertext: new_frag = new_ptxt_at_pos XOR ks
new_frag = bytes([a ^ b for a, b in zip(new_ptxt_at_pos, ks)])

# Substituir o fragmento no ciphertext
ciphertext[pos: pos+len(new_frag)] = new_frag

# Escrever o ficheiro modificado
output_file = fctxt + ".attck"
with open(output_file, "wb") as outf:
    outf.write(nonce + ciphertext)
print("Arquivo manipulado e salvo em", output_file)
