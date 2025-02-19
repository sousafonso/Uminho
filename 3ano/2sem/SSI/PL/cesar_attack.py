import sys

def decrypt(text, shift):
    result = []
    for ch in text:
        if ch.isalpha(): # se for uma letra do alfabeto
            base = ord('A') if ch.isupper() else ord('a')
            result.append(chr((ord(ch) - base - shift) % 26 + base))
        else:
            result.append(ch)
    return ''.join(result)

if len(sys.argv) < 3:
    sys.exit()

cryptogram = sys.argv[1]
keywords = sys.argv[2:]

for key in range(26):
    plaintext = decrypt(cryptogram, key)
    # Verifica se alguma das palavras-chave ocorre no texto limpo (ignorando caixa)
    if any(word.lower() in plaintext.lower() for word in keywords):
        print(key)
        print(plaintext)
        sys.exit()

