import ply.lex as lex
import re

frases = """
Olá, mundo! Este é um teste.
"""

tokens = [
    'PALAVRA',
    'VIRGULA',
    'PONTUACAO',
]

t_VIRGULA   = r','
t_PONTUACAO = r'[\.!\?;:]'
t_PALAVRA   = r'[A-Za-zÀ-ÿ]+'

t_ignore = ' \t\n'

def t_error(t):
    print(f"Caracter ilegal: {t.value[0]}")
    t.lexer.skip(1)

lexer = lex.lex()

if __name__ == '__main__':
    lexer.input(frases)
    for tok in lexer:
        print(tok)
