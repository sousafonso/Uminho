import ply.lex as lex
import re

programa = """
    int main(){
        printf("Hello World", "Aqui tem duas \"\"\!\n");
        // variável
        int x2 = 34 + 34;
        return 3/5;
    }
"""

tokens = [
    'COMMENT',
    'NUM',
    'ID',
    'INT',
    'RETURN',
    'STRING'
]

t_ignore = ' \t\n'
literals = "{}();=+-*/"

def t_COMMENT(t):
    r"/{2}.*"
    t.value = re.sub(r"//", "", t.value)
    return t

def t_STRING(t):
    r'"([^\n"\\]|\\.)*?"'
    return t

def t_INT(t):
    r'int'
    return t 

def t_RETURN(t):
    r'return'
    return t  

def t_NUM(t):
    r'\d+'
    t.value = int(t.value)
    return t

def t_ID(t):
    r'[a-zA-Z_]\w*'
    return t

def t_error(t):
    print(f"Illegal character {t.value[0]}")
    t.lexer.skip(1)


lexer = lex.lex()
lexer.input(programa)

for tok in lexer:
    print(tok)
