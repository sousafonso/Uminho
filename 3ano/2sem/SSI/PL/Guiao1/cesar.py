import sys

def cifrar_cesar(chave, mensagem):
    resultado = ""
    for letra in mensagem.upper():
        if letra.isalpha():
            # Calcula a nova letra considerando a chave
            nova_letra = chr((ord(letra) - ord('A') + chave) % 26 + ord('A'))
            resultado += nova_letra
        else:
            resultado += letra
    return resultado

def decifrar_cesar(chave, mensagem):
    return cifrar_cesar(-chave, mensagem)

def main():
    if len(sys.argv) != 4:
        print("Uso: python3 cesar.py <enc/dec> <chave> <mensagem>")
        sys.exit(1)

    operacao = sys.argv[1]
    chave = sys.argv[2].upper()
    mensagem = sys.argv[3]

    if len(chave) != 1 or not chave.isalpha():
        print("A chave deve ser uma única letra de A a Z.")
        sys.exit(1)

    chave_num = ord(chave) - ord('A')

    if operacao == "enc":
        resultado = cifrar_cesar(chave_num, mensagem)
    elif operacao == "dec":
        resultado = decifrar_cesar(chave_num, mensagem)
    else:
        print("Operação inválida. Use 'enc' para cifrar ou 'dec' para decifrar.")
        sys.exit(1)

    print(resultado)

if __name__ == "__main__":
    main()