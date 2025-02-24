def pessoas():
    pessoas = dict()

    while input("Deseja inserir uma pessoa? (s/n)") == "s":
        pessoa = input("Insira uma pessoa:")
        idade = input ("indique a idade de "+ pessoa + " : ")
        pessoas [pessoa] = idade

    if len(pessoas) > 0:
        mais_velha = max(pessoas, key=pessoas.get)
        print ("A pessoa mais velha é a/o " , mais_velha)
    else:
        print ("Dicionario vazio")