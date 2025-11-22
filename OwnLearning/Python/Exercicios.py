import random
import json

# Escreva um programa que leia um número inteiro do utilizador e apresente o seu antecessor e sucessor.
def antecessor_sucessor(numero):
    antecessor = numero - 1
    sucessor = numero + 1
    print("Antecesso: " + antecessor)
    print("\nNumero: " + numero)
    print("\nSucessor: " + sucessor)

# Desenvolva um programa que leia a base e a altura de um retângulo e calcule a sua área.
def area_retangulo(base, altura):
    return base * altura

# Crie um programa que converta uma temperatura de Celsius para Fahrenheit.
def temp_conversor(celsius):
    return (9/5) * celsius + 32

# Escreva um programa que determine se um número inteiro é par ou ímpar.
def par_impar (numero):
    if numero % 2 == 0:
        return "Par"
    else:
        return "Impar"
    
# Desenvolva um programa que leia quatro notas e calcule a média aritmética.
def media_notas (nota1, nota2, nota3, nota4):
    return (nota1 + nota2 + nota3 + nota4)/4

# Crie um programa que leia três números e identifique qual é o maior
def maior (num1, num2 , num3):
    if num1 > num2:
        if num1 > num3:
            return num1
    elif num1 < num2:
        if num2 > num3:
            return num2
    else:
        return num3

# Escreva um programa que leia a idade de uma pessoa e classifique-a em: criança (0-12), adolescente (13-17), adulto (18-59) ou idoso (60+).
def classifica_idade(idade):
    if 0 <= idade <= 12:
        return "Criança"
    elif 13 <= idade <= 17:
        return "Adolescente"
    elif 18 <= idade <= 59:
        return "Adulto"
    else:
        return "Idoso"
    
# Desenvolva uma calculadora de Índice de Massa Corporal (IMC) que classifique o resultado.
def imc (peso, altura):
    imc = peso/(altura ** 2)

    if imc < 18.5:
        return "Abaixo do peso"
    elif 18.5 <= imc < 25:
        return "Peso normal"
    elif 25 <= imc < 30:
        return "Sobrepeso"
    else:
        return "Obeso"
    
# Crie um programa que determine se um ano é bissexto.
def bissexto (ano):
    if (ano % 4 == 0 and not ano % 100 == 0) or ano % 400 == 0:
        return "Bissexto"
    else:
        return "Não bissexto"
    
# Desenvolva uma calculadora que realize as quatro operações básicas (+, -, *, /) conforme escolha do utilizador.
def calculadora (num1, num2, op):
    match op:
        case "+":
            return num1 + num2
        case "-":
            return num1 - num2
        case "*":
            return num1 * num2
        case "/":
            return num1/num2
        
# Escreva um programa que converta um valor em segundos para o formato horas:minutos:segundos.
def convers_segundos (total):
    horas = total // 3600
    minutos = int(total / 60 - 60)
    segundos = total % 60

    return horas + ":" + minutos + ":" + segundos

# Crie um programa que apresente a tabuada de multiplicação de um número fornecido pelo utilizador (de 1 a 10).
def tabuada (num):
    for i in range(1, 11):
        print(num*i)

# Desenvolva um programa que calcule a soma de todos os números pares entre 1 e 100.
def soma_pares():
    soma = 0
    for i in range(2,100,2):
        soma += i
    return soma

# Escreva um programa que calcule o fatorial de um número inteiro positivo.
def fatorial (num):
    if num == 0:
        return 1
    return num * fatorial(num - 1)

# Escreva um programa que conte o número de vogais (a, e, i, o, u) numa string fornecida pelo utilizador
def conta_vogais(palavra):
    contador = 0
    palavra = palavra.lower()
    for l in palavra:
        if l in ["a","e","i","o","u"]:
            contador += 1
    return contador
    
# Desenvolva um programa que inverta uma string sem usar métodos prontos.
def reverse (palavra : str):
    nova_palavra = ""
    for l in palavra:
        nova_palavra -= l
    return nova_palavra

# Escreva um programa que conte o número de palavras numa frase.
def conta_words (palavra : str):
    words = palavra.split() 
    
"""
 Desenvolva um programa que valide uma senha segundo os critérios:
• Mínimo 8 caracteres
• Pelo menos uma letra maiúscula
• Pelo menos uma letra minúscula
• Pelo menos um dígito
• Pelo menos um caractere especial (!@#$%&*)

"""
def ver_password (password: str):
    special_chars = ["!", "#", "*", "@", "$", "%", "&"]
    return password.len() >= 8 and password.isdigit() and password.islower() and password.isupper() and any(substr in password for substr in special_chars)

"""

 Crie um jogo onde o programa escolhe um número aleatório entre 1 e 100, e o utilizador tenta adivinhar.
 Requisitos:
    • Dar dicas ("maior" ou "menor")
    • Contar o número de tentativas
    • Usar o módulo random

"""

def adivinha (numero):
    star = random.randint(1,100)

    if int(numero) == star:
        return "BOAAAA"
    elif int(numero) < star:
        print ("Maior")
    elif int(numero) > star:
        print("Menor")
    else:
        return
    
# Escreva um programa que faça uma contagem regressiva de N até 0, apresentando "Lançamento!" no final.
def lancamento(n):
    while n > 0:
        print(n)
        n - 1
    print("Lancamento")

# Desenvolva um programa que calcule a soma dos dígitos de um número inteiro.
def soma_digit(word: str):
    lower_word = word.lower()
    somador = 0
    for n in lower_word:
        somador = int(n)

    return somador

def are_all_digits(word:str):
    return not word.isalpha()

def formata_nomes(nome: str):
    lista = nome.split()
    formatacao = list(map(lambda x : x.title(), lista))
    done = " ".join(formatacao)
    print(done)

# Desenvolva um programa que converta um número binário (string) para decimal
def convert_bin():
    binario = input("Digite um número binário: ")
    decimal = 0
    potencia = 0
    for i in range(len(binario) - 1, -1, -1):
        if binario[i] == '1':
            decimal += 2 ** potencia
        potencia += 1
    print(f"Binário {binario} = Decimal {decimal}")

def remove_dups():
    lista = [1, 2, 2, 3, 4, 3, 5, 1, 6, 4]

    # Remover duplicados mantendo ordem
    lista_sem_duplicados = []
    vistos = set()   

    for elemento in lista:
        if elemento not in vistos:
            lista_sem_duplicados.append(elemento)
            vistos.add(elemento)

    print(f"Lista original: {lista}")
    print(f"Sem duplicados: {lista_sem_duplicados}")

    # Alternativa usando dict (Python 3.7+)
    # lista_sem_duplicados = list(dict.fromkeys(lista))

# Desenvolva um programa que encontre o segundo maior elemento numa lista sem ordená-la completamente.
def maior (lista):
    maior = lista [0]
    for i in range(2, len(lista)):
        if lista [i] > maior:
            maior = lista[i]

    return maior

# Crie um programa que rode uma lista N posições para a direita.
def rotate_right(lista, n):
    n = n % len(lista)  # Garantir que n está dentro do tamanho da lista
    return lista[-n:] + lista[:-n]

# Escreva um programa que conte a frequência de cada elemento numa lista e retorne um dicionário.
def freq (lista: list):
    frequencias = {}

    for elemento in lista:
        frequencias[elemento] = frequencias.get(elemento, 0) + 1

    print("Frequências:")
    for elemento, freq in frequencias.items():
        print(f"{elemento}: {freq}")

# Desenvolva um programa que una dois dicionários. Se houver chaves repetidas, some os valores.
def join_dics (dict1: dict, dict2: dict):
    resultado = dict1.copy()

    for chave, valor in dict2.items():
        if chave in resultado:
            resultado[chave] += valor
        else:
            resultado[chave] = valor

# Matriz transposta
def transposta(matriz):
    linhas = len(matriz)
    colunas = len(matriz[0])
    transposta = []

    for j in range(colunas):
        nova_linha = []
        for i in range(linhas):
            nova_linha.append(matriz[i][j])
        transposta.append(nova_linha)

    return transposta

# Escreva um programa que converta uma lista de tuplos (chave, valor) num dicionário.
def convert_to_dict (lista: list):
    dic = {}
    for chave, valor in lista:
        dic[chave] = valor

# Dada uma lista de tuplos (nome, idade), ordene-a por idade usando uma função lambda.
def ordena_list (pessoas: list):
    pessoas_ordenadas = sorted(pessoas, key=lambda x: x[1])
    return pessoas_ordenadas

"""
Exercício 46: Leitura e Escrita de Ficheiros
    Desenvolva um programa que:
    1. Leia o conteúdo de um ficheiro de texto
    2. Conte o número de palavras
    3. Escreva o resultado num novo ficheiro
"""

def ler_ficheiro (file):
    try:
        # Ler ficheiro
        with open(file, 'r', encoding='utf-8') as f:
            conteudo = f.read()
        
        # Contar palavras
        palavras = conteudo.split()
        num_palavras = len(palavras)
        
        # Escrever resultado
        with open(file, 'w', encoding='utf-8') as f:
            f.write(f"Ficheiro: {file}\n")
            f.write(f"Número de palavras: {num_palavras}\n")
        
        print(f"Processamento concluído. Resultado em '{file}'")
        
    except FileNotFoundError:
        print(f"Erro: Ficheiro '{file}' não encontrado")
    except Exception as e:
        print(f"Erro: {e}")

"""

Exercício 50: Sistema de Gestão de Contactos
Desenvolva um sistema simples que permita:

• Adicionar contacto (nome, telefone, email)
• Remover contacto
• Pesquisar contacto por nome
• Listar todos os contactos
• Guardar e carregar contactos de um ficheiro JSON

"""

contactos = {}
file_contactos = "./seila"

def add_contacto (nome:str, telefone: str, email: str):
    contactos[nome] = {
        "telefone": telefone,
        "email": email
    }

def remove_contacto (nome: str):
    if nome in contactos:
        del contactos[nome]

def search_contacto (nome: str):
    return contactos.get(nome, "Contacto não encontrado")

def list_contactos():
    return contactos

def load_contactos():
    global contactos
    try:
        with open (file_contactos, 'r', encoding='utf-8') as f:
            contactos = json.load(f)
    except FileNotFoundError:
        contactos = {}

def save_contacto (contactos: dict):
    with open (file_contactos, 'w', encoding='utf-8') as f:
        json.dump(contactos, f, ensure_ascii=False, indent=4)


class ContaBancaria:
    def __init__ (self, titular, saldo, historico):
        self.titular = titular
        self.saldo = saldo
        self.historico = historico

    def depositar(self, valor):
        self.saldo += valor
        self.historico.append(f"Depósito: {valor}")
        return True
    
    def levantar(self, valor): 
        self.saldo -= valor
        self.historico.append(f"Levantamento: {valor}")
        return True
    
    def transferir(self, destino, valor): 
        if valor <= 0:
            print("Valor deve ser positivo")
            return False
        
        if valor > self.saldo:
            print("Saldo insuficiente")
            return False
        
        self.saldo -= valor
        destino.saldo += valor
        
        self.historico.append(f"Transferência enviada: €{valor:.2f} para {destino.titular}")
        destino.historico.append(f"Transferência recebida: €{valor:.2f} de {self.titular}")
        
        print(f"Transferência de €{valor:.2f} realizada com sucesso")
        return True
    
    def extrato(self):
        return self.historico
    
    def consultar_saldo(self):
        return self.saldo

class Veiculo:
    def __init__ (self, marca, modelo, ano, ligado : bool):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.ligado = ligado

    def ligar(self):
        """Liga o veículo."""
        if not self.ligado:
            self.ligado = True
            print(f"{self.modelo} ligado")
        else:
            print(f"{self.modelo} já está ligado")

    def desligar (self):
        """Desliga o veículo."""
        if self.ligado:
            self.ligado = False
            print(f"{self.modelo} desligado")
        else:
            print(f"{self.modelo} já está desligado")

    def informacoes(self):
        """Apresenta informações do veículo."""
        estado = "Ligado" if self.ligado else "Desligado"
        print(f"\n=== Informações do Veículo ===")
        print(f"Marca: {self.marca}")
        print(f"Modelo: {self.modelo}")
        print(f"Ano: {self.ano}")
        print(f"Estado: {estado}")


class Carro(Veiculo):
    def __init__(self, num_portas: int):
        super().__init__(marca, modelo, ano)
        self.num_portas = num_portas

    def informacoes(self):
        """Apresenta informações do carro."""
        super().informacoes()
        print(f"Número de portas: {self.num_portas}")
        print(f"Tipo: Carro")

class Mota(Veiculo):
    def __init__(self, cilindrada: int):
        super().__init__(marca, modelo, ano)
        self.cilindrada = cilindrada
        
    def informacoes(self):
        """Apresenta informações da moto."""
        super().informacoes()
        print(f"Cilindrada: {self.cilindrada}cc")
        print(f"Tipo: Moto")

def procura_binaria(lista: list, elemento):
    esquerda = 0
    direita = len(lista) - 1
    
    while esquerda <= direita:
        meio = (esquerda + direita) // 2
        
        if lista[meio] == valor:
            return meio
        elif lista[meio] < valor:
            esquerda = meio + 1
        else:
            direita = meio - 1
    
    return -1

# Versão recursiva
def busca_binaria_recursiva(lista, valor, esquerda=0, direita=None):
    """Busca binária recursiva."""
    if direita is None:
        direita = len(lista) - 1
    
    if esquerda > direita:
        return -1 # elemento não encontrado
    
    meio = (esquerda + direita) // 2
    
    if lista[meio] == valor:
        return meio 
    elif lista[meio] < valor:
        return busca_binaria_recursiva(lista, valor, meio + 1, direita)
    else:
        return busca_binaria_recursiva(lista, valor, esquerda, meio - 1)
    