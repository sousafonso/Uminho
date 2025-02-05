#Função que inverte uma string
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
    for i in range (lista.len()):
        sum += 1