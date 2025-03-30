import ply.lex as lex

tokens = (
    'CATEGORIA',
    'COLON',
    'DASH',
    'DOUBLECOLON',
    'NOME',
    'NUMERO',
    'VALOR',       # <-- Token adicionado
    'SEMICOLON',
)

# Valor com ponto decimal
def t_VALOR(t):
    r'\d+\.\d+'
    t.value = float(t.value)
    return t

# Números inteiros (para ordem e quantidade)
def t_NUMERO(t):
    r'\d+'
    t.value = int(t.value)
    return t

# As categorias devem ter prioridade
def t_CATEGORIA(t):
    r'[A-Z]{2,}'
    return t

def t_NOME(t):
    r'[\w\s]+'
    return t

# Expressões regulares simples para tokens
t_COLON       = r':'
t_DASH        = r'\-'
t_DOUBLECOLON = r'\:\:'
t_SEMICOLON   = r';'

# Caracteres ignorados (espaços e tabs)
t_ignore = '\n\t '

# Nova linha
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

# Tratamento de erro
def t_error(t):
    print(f"Caractere ilegal '{t.value[0]}'")
    t.lexer.skip(1)

lexer = lex.lex()

if __name__ == "__main__":
    data = """
CARNE :
  - 1 :: Bife :: 10.00 :: 1;
  - 2 :: Panado :: 5.00 :: 4;
  - 3 :: Hambúrguer :: 8.00 :: 3;
  - 4 :: Almôndegas :: 7.00 :: 5;

BEBIDA :
  - 5 :: Água :: 0.40 :: 16;
  - 6 :: Sumo :: 1.50 :: 9;
  - 7 :: Refrigerante :: 1.80 :: 10;

FRUTA :
  - 8 :: Maçã :: 0.60 :: 20;
  - 9 :: Banana :: 0.50 :: 15;
  - 10 :: Laranja :: 0.80 :: 18;
  - 11 :: Pêssego :: 0.70 :: 22;
  - 12 :: Uva :: 0.90 :: 17;

LEGUMES :
  - 13 :: Alface :: 1.00 :: 25;
  - 14 :: Tomate :: 0.75 :: 23;
  - 15 :: Cebola :: 0.50 :: 28;
  - 16 :: Batata :: 0.30 :: 30;
  - 17 :: Cenoura :: 0.40 :: 26;

PASTELARIA :
  - 18 :: Bolo de Chocolate :: 3.50 :: 1;
  - 19 :: Croissant :: 1.20 :: 14;
  - 20 :: Pastel de Nata :: 1.00 :: 5;
  - 21 :: Donut :: 0.80 :: 13;
    """
    lexer.input(data)
    for tok in lexer:
        print(tok)