import re

# Especificação dos tokens
TOKEN_SPECIFICATION = [
    ("OPEN_END_TAG", r"</"),                                 # Início de tag de fechamento
    ("SELF_CLOSING", r"/>"),                                  # Tag autônoma
    ("OPEN_TAG", r"<"),                                      # Início de tag
    ("CLOSE_TAG", r">"),                                     # Fim de tag
    ("EQUAL", r"="),                                         # Igual (atributo)
    ("STRING", r'"[^"]*"'),                                  # Valor de atributo entre aspas duplas
    ("NAME", r"[a-zA-Z_:][a-zA-Z0-9\.\-_:]*"),               # Nome de tag ou atributo
    ("TEXT", r"[^<>\s][^<>]*"),                              # Texto (conteúdo entre tags)
    ("SKIP", r"[ \t\n]+"),                                   # Espaços em branco
    ("MISMATCH", r"."),                                      # Qualquer outro caractere
]

Token = lambda tipo, valor: (tipo, valor)

def generate_tokens(codigo):
    # Constrói a expressão regular mestre
    token_regex = "|".join(f"(?P<{nome}>{padrao})" for nome, padrao in TOKEN_SPECIFICATION)
    for match in re.finditer(token_regex, codigo):
        kind = match.lastgroup
        value = match.group()
        if kind == "SKIP":
            continue
        elif kind == "MISMATCH":
            raise RuntimeError(f"Caracter inesperado {value!r}")
        else:
            yield Token(kind, value)

if __name__ == "__main__":
    # Exemplo de uso
    xml_input = '''<note>
  <to>User</to>
  <from>Library</from>
  <heading reminder="yes">Reminder</heading>
  <body>Don't forget the meeting!</body>
</note>'''
    
    print("Tokens:")
    for token in generate_tokens(xml_input):
        print(token)