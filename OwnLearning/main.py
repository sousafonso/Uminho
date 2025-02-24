#Função que inverte uma string
from Pessoas import pessoas
from Quadrados import lista_quadrados
from Tabuada import tabuada
from num_caracteres import caracteres
import string

class Carro:
    def __init__(self, marca, modelo, ano):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano

    def acelerar(self):
        print("Acelerandoooooo!")
    def travar (self):
        print("travandooooooo!")

meu_carro = Carro("Toyota", "Corolla")
meu_carro.acelerar()

def invert_String (string):
    return string[::-1]

#Função que permite calcular o factorial de um número
def calcular_fatorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * calcular_fatorial(n - 1)
    
#Função que permite saber se uma dada string é lida da mesma forma da esquerda para a direita e da direita para a esquerda
def eh_palindromo(string):
    string = string.lower()
    return string == string[::-1]

#Função que gere os primeiros n números da sequencia de fibonacci
def gerar_fibonacci(n):
    fibonacci = []  # Lista para armazenar a sequência
    if n >= 1:
        fibonacci.append(0)  # Adiciona o primeiro número (F(0) = 0)
    if n >= 2:
        fibonacci.append(1)  # Adiciona o segundo número (F(1) = 1)
    
    # Gera os próximos números da sequência
    for i in range(2, n):
        proximo = fibonacci[i-1] + fibonacci[i-2]  # F(n) = F(n-1) + F(n-2)
        fibonacci.append(proximo)
    
    return fibonacci

def fibonacci_recursivo(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2)
    
#Função que recebe uma lista e retorna a soma dos elementos
def soma_lista (lista):
    sum = 0
    for i in range(len(lista)):
        sum += lista[i]
    return sum

def isLista(lista : list):
    print(lista)

def removeDuplicados (lista):
    lista2 = []
    lista.sort()
    for elem1 in lista:
        if elem1 not in lista2:
                lista2.append(elem1)
    print (lista2)

def calculadora (num1, num2, operador):
    if operador == "+":
        print(">> ", (num1+num2))
    elif operador == "-":
        print(">> ", (num1-num2))
    elif operador == "*":
        print(">> ", (num1*num2))
    else:
        print(">> ", (num1 / num2))

def average (lista : list):
    soma = sum(lista)

    avg = soma / len(lista)
    print ("A média da lista é", avg)      

def num_pares (lista):
    lista2 = []
    for elem in lista:
        if elem % 2 == 0:
            lista2.append(elem)
    print (lista2)

def num_of_words (texto):
    texto = texto.split()
    print ("O texto tem", len(texto), "palavras")

# 26
def lista_inversa (texto):
    texto = texto.split()

    print(texto)

    texto = texto[::-1]

    print(texto)

def maior_palavra (lista):
    maior = lista [0]

    for palavra in lista:
        if len(palavra) > len(maior):
            maior = palavra

    print("A maior palavra é " , maior)

def soma_quadrados (lista):
    soma = 0
    for elem in lista:
        soma += elem ** 2
    print(soma)

def palavra_caps (word):
    word = word.upper()
    print(word)

def segundo_maior (lista):
    lista.sort()
    print (lista[-2])

def ordem_alfabetica (words):
    words.sort()
    print(words)

def lista_quadrados(lista):
    lista2 = []

    for num in lista:
        lista2.append(num**2)

    print(lista2)

def produto (lista):
    produto = 0

    for num in lista:
        produto *= num

    print (produto)

def ordena_word (palavra):
    palavra = list(palavra)
    palavra.sort()
    palavra = ''.join(palavra)
    print(palavra)

def impares (lista):
    lista2 = []

    for num in lista:
        if num % 2 != 0:
            lista.append(num)

    print(lista)

def mais_curta (lista):
    menor = lista [0]

    for palavra in lista:
        if len(palavra) < len(menor):
            menor = palavra

    print("A menor palavra é " , menor)

def media (lista):
    media = 0
    soma = 0

    for num in lista:
        soma += num

    media = soma / len(lista)

    print(media)

def num_vogais (word):
    vogais = 0
    for c in word:
        if c in "aeiou":
            vogais += 1

    print(vogais)

def main():
    # print(invert_String("Ola Mundo"))
    # print(calcular_fatorial(5))
    # print(eh_palindromo("Ovo"))
    # print(gerar_fibonacci(10))
    # print(fibonacci_recursivo(10))
    # print(soma_lista([1,2,3,4,5]))
    # tabuada(10)
    #pessoas()
    #caracteres()
    #lista_quadrados()
    # isLista([])
    # removeDuplicados([2,1,5,3,2,2,5,6,8,9])

    # print("Vamos fazer contas?")
    # conta = input()

    # calculadora (float (conta[0]), float (conta[4]), conta[2])

    # average ([1,2,3,4,5,6,7,8,9])

    # num_pares ([2,2,2,2,4,4,5,7,8,9,11,13])

    # num_of_words("OLÁ PUTA DOIS")

    # lista_inversa ("OLÁ PUTA DOIS")

    # maior_palavra (['oláaaaaa' , 'olaaa', 'pedro', 'otarrinolaringologista'])

    # soma_quadrados([1,2,3,4,5,6,7,8,9,10])

    # segundo_maior([1,2,3,4,5,6,7,8,9,10])

    # ordem_alfabetica(["ola", "puta", "dois", "caralho"])

    # lista_quadrados([1,2,3,4,5,6,7,8,9,10])

    # produto([1,2,3,4,5,6,7,8,9,10])

    ordena_word("olá")
    
if __name__ == "__main__":
    main()