import random


def maior ():
    lista = list

    for i in range(6):
        x = random.randrange(1,100)
        lista.append(x)

    maior = lista [0]
    menor = lista [0]

    for i in range (6):
        if (lista[i] > maior): maior = lista [i]
        if (lista[i] < menor): menor = lista [i]

    print ("O maior elemento é" + maior)
    print ("O menor elemento é" + menor)