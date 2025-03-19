import sys

def decifrar_cesar(chave, cryptograma):
    texto_limpo = ""
    for letra in cryptograma.upper():
        if letra.isalpha():
            # Decifra a letra considerando a chave
            nova_letra = chr(((ord(letra) - ord('A') - chave) % 26 + ord('A')))
            texto_limpo += nova_letra
        else:
            texto_limpo += letra
    return texto_limpo

def atacar_cesar(cryptograma, palavras):
    for chave in range(26):  # Testa todas as 26 chaves possíveis
        texto_limpo = decifrar_cesar(chave, cryptograma)
        # Verifica se alguma das palavras está no texto decifrado
        for palavra in palavras:
            if palavra.upper() in texto_limpo:
                return chave, texto_limpo
    return None, ""  # Retorna vazio se nenhuma chave for encontrada

def main():
    if len(sys.argv) < 3:
        print("Uso: python3 cesar_attack.py <cryptograma> <palavra1> <palavra2> ...")
        sys.exit(1)

    cryptograma = sys.argv[1]
    palavras = sys.argv[2:]  # Lista de palavras para verificar

    chave, texto_limpo = atacar_cesar(cryptograma, palavras)

    if chave is not None:
        print(chave)
        print(texto_limpo)
    else:
        print("")  # Resposta vazia se nenhuma chave for encontrada

if __name__ == "__main__":
    main()