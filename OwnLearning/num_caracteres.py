def caracteres ():
    alf = dict({a : 0 for a in "abcdefghijklmnopqrstuvwxyz"})

    texto = input("Digite algo....")

    texto = texto.lower()

    for c in texto:
        if c not in alf:
            alf[c] = 1
        else:
            alf [c] += 1

    print (alf)

