def contar_vogais(string):
    vogais = "aeiouAEIOU"
    return sum(1 for caractere in string if caractere in vogais)