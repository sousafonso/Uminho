def encrypt(key, text):
    result = ""
    for i, ch in enumerate(text):
        # Calcula o deslocamento com base no caractere da chave: 'A' -> 0, 'B' -> 1, etc.
        shift = ord(key[i % len(key)].upper()) - ord('A')
        if ch.isalpha():
            # Preserva (uppercase/lowercase) e aplica a cifra de César com o deslocamento da chave
            result += chr((ord(ch) - ord('A') + shift) % 26 + ord('A'))
        else:
            result += ch
    return result.upper()

def decrypt(key, text):
    result = ""
    for i, ch in enumerate(text):
        # Calcula o deslocamento com base no caractere da chave
        shift = ord(key[i % len(key)].upper()) - ord('A')
        if ch.isalpha():
            result += chr((ord(ch) - ord('A') - shift) % 26 + ord('A'))
        else:
            result += ch
    return result

def main(args):
    if len(args) < 4:
        return
    key = args[2]
    text = args[3]

    if args[1] == "enc":
        print(encrypt(key, text))
    elif args[1] == "dec":
        print(decrypt(key, text))

if __name__ == "__main__":
    import sys
    main(sys.argv)