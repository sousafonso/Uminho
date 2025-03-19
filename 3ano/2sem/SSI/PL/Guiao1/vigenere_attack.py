import sys
from collections import Counter

# Frequência das letras no português (ordem decrescente)
FREQUENCIA_LETRAS = "AEOSRIDNMUTCLPVGHQBFZJXKYW"

def decifrar_cesar(chave, cryptograma):
    texto_limpo = ""
    for letra in cryptograma.upper():
        if letra.isalpha():
            nova_letra = chr(((ord(letra) - ord('A') - chave) % 26 + ord('A')))
            texto_limpo += nova_letra
        else:
            texto_limpo += letra
    return texto_limpo

def calcular_frequencia(texto):
    """Calcula a frequência das letras no texto."""
    contador = Counter(texto.upper())
    total_letras = sum(contador.values())
    return {letra: contador[letra] / total_letras for letra in contador if letra.isalpha()}

def comparar_frequencias(frequencia_texto):
    """Compara a frequência das letras no texto com a frequência esperada no português."""
    # Ordena as letras do texto por frequência (decrescente)
    letras_ordenadas = sorted(frequencia_texto.keys(), key=lambda x: -frequencia_texto[x])
    # Compara com a ordem esperada no português
    pontuacao = 0
    for i, letra in enumerate(letras_ordenadas):
        if letra in FREQUENCIA_LETRAS:
            pontuacao += abs(i - FREQUENCIA_LETRAS.index(letra))
    return pontuacao

def atacar_fatia(fatia):
    """Ataca uma fatia do criptograma usando a frequência das letras."""
    melhor_chave = 0
    melhor_pontuacao = float('inf')

    for chave in range(26):  # Testa todas as 26 chaves possíveis
        texto_decifrado = decifrar_cesar(chave, fatia)
        frequencia = calcular_frequencia(texto_decifrado)
        pontuacao = comparar_frequencias(frequencia)

        if pontuacao < melhor_pontuacao:
            melhor_pontuacao = pontuacao
            melhor_chave = chave

    return melhor_chave

def atacar_vigenere(tamanho_chave, cryptograma, palavras):
    # Divide o cryptograma em fatias
    fatias = [""] * tamanho_chave
    for i, letra in enumerate(cryptograma.upper()):
        if letra.isalpha():
            fatias[i % tamanho_chave] += letra

    # Ataca cada fatia para encontrar a chave
    chave = []
    for fatia in fatias:
        chave_fatia = atacar_fatia(fatia)
        chave.append(chave_fatia)

    # Converte a chave numérica para letras
    chave_letras = "".join([chr(c + ord('A')) for c in chave])

    # Decifra o cryptograma completo com a chave encontrada
    texto_limpo = ""
    for i, letra in enumerate(cryptograma.upper()):
        if letra.isalpha():
            chave_index = i % tamanho_chave
            texto_limpo += decifrar_cesar(chave[chave_index], letra)
        else:
            texto_limpo += letra

    # Verifica se alguma das palavras está no texto decifrado
    for palavra in palavras:
        if palavra.upper() in texto_limpo:
            return chave_letras, texto_limpo

    return None, ""  # Resposta vazia se nenhuma palavra for encontrada

def main():
    if len(sys.argv) < 4:
        print("Uso: python3 vigenere_attack.py <tamanho_chave> <cryptograma> <palavra1> <palavra2> ...")
        sys.exit(1)

    tamanho_chave = int(sys.argv[1])
    cryptograma = sys.argv[2]
    palavras = sys.argv[3:]  # Lista de palavras para verificar

    chave, texto_limpo = atacar_vigenere(tamanho_chave, cryptograma, palavras)

    if chave:
        print(chave)
        print(texto_limpo)
    else:
        print("")  # Resposta vazia se nenhuma chave for encontrada

if __name__ == "__main__":
    main()