import ply.yacc as yacc
from tokenizer import tokens

# Gramática:
#
# categorias : categoria
#            | categorias categoria
#
# categoria  : CATEGORIA COLON produtos 
#
# produtos   : produto 
#            | produtos produto
#
# produto    : DASH NUMERO DOUBLECOLON NOME DOUBLECOLON VALOR DOUBLECOLON NUMERO SEMICOLON

def p_categorias_single(p):
    "categorias : categoria"
    p[0] = [ p[1] ]

def p_categorias_recursive(p):
    "categorias : categorias categoria"
    p[0] = p[1] + [ p[2] ]

def p_categoria(p):
    "categoria : CATEGORIA COLON produtos"
    p[0] = {
        'nome': p[1],
        'lista': p[3],
        'total': sum(produto['valor'] * produto['quantidade'] for produto in p[3])
    }

def p_produtos_single(p):
    "produtos : produto"
    p[0] = [ p[1] ]

def p_produtos_recursive(p):
    "produtos : produtos produto"
    p[0] = p[1] + [ p[2] ]

def p_produto(p):
    "produto : DASH NUMERO DOUBLECOLON NOME DOUBLECOLON VALOR DOUBLECOLON NUMERO SEMICOLON"
    p[0] = {
        'id': p[2],
        'nome': p[4].strip(),
        'valor': p[6],
        'quantidade': p[8]
    }

def p_error(p):
    if p:
        print(f"Syntax error at token {p.type}")
    else:
        print("Syntax error at EOF")

parser = yacc.yacc()

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
    result = parser.parse(data)
    print(result)