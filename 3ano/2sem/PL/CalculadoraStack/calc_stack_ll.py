import re

class Lexer():
    def __init__(self):
        self.tokens = []
    
    def tokenizer(self, data):
        if data == '':
            return self.tokens
        if data[0].isspace():
            return self.tokenizer(data[1:])
        if data[0:4] == 'PUSH':
            self.tokens.append('PUSH')
            return self.tokenizer(data[4:])
        if data[0:3] == 'POP':
            self.tokens.append('POP')
            return self.tokenizer(data[3:])
        if data[0:2] == 'OP':
            self.tokens.append('OP')
            return self.tokenizer(data[2:])
        if data[0:4] == 'SWAP':
            self.tokens.append('SWAP')
            return self.tokenizer(data[4:])
        if (m := re.match(r'^\d+', data)):
            value = m.group(0)
            self.tokens.append(("INT", int(value)))
            return self.tokenizer(data[len(value):])
        if data[0] in ['+', '-', '*', '/']:
            self.tokens.append(data[0])
            return self.tokenizer(data[1:])
        return "ERROR"

class Parser():
    def __init__(self, tokens):
        self.input = tokens
        self.stack = []

    def parse(self):
        self.parse_S()

    def parse_S(self):
        "S -> instrucoes | ε"
        if self.input:
            self.parse_instrucoes()

    def parse_instrucoes(self):
        "instrucoes -> instrucao instrucoes"
        self.parse_instrucao()
        self.parse_instrucoes_()

    def parse_instrucoes_(self):
        "instrucoes_ -> instrucao instrucoes_ | ε"
        if not self.input:
            return
        elif self.input[0] in ['PUSH', 'POP', 'SWAP', 'OP']:
            self.parse_instrucao()
            self.parse_instrucoes_()
        else:
            raise SyntaxError("Invalid instruction sequence")
        
    def parse_instrucao(self):
        if not self.input:
            raise SyntaxError("Fim inesperado da entrada ao esperar por uma instrução")
        match self.input[0]:
            case 'PUSH':
                self.input.pop(0)
                if not self.input:
                    raise SyntaxError("Fim inesperado da entrada após PUSH")
                match self.input[0]:
                    case ('INT', value):
                        self.input.pop(0)
                        self.stack.append(int(value))
                    case _:
                        raise SyntaxError(f"Expected INT, got {self.input[0]}")
            case 'POP':
                self.input.pop(0)
                if self.stack:
                    value = self.stack.pop()
                    print(f"Popped value: {value}")
                else:
                    raise IndexError("Stack is empty")
            case 'SWAP':
                self.input.pop(0)
                if len(self.stack) < 2:
                    raise IndexError("Not enough elements in stack to swap")
                value1 = self.stack.pop()
                value2 = self.stack.pop()
                self.stack.append(value1)
                self.stack.append(value2)
            case 'OP':
                self.input.pop(0)
                if not self.input:
                    raise SyntaxError("Fim inesperado da entrada após OP")
                match self.input[0]:
                    case '+':
                        self.input.pop(0)
                        self.stack.append(self.stack.pop() + self.stack.pop())
                    case '-':
                        self.input.pop(0)
                        value1 = self.stack.pop()
                        value2 = self.stack.pop()
                        self.stack.append(value2 - value1)
                    case '*':
                        self.input.pop(0)
                        self.stack.append(self.stack.pop() * self.stack.pop())
                    case '/':
                        self.input.pop(0)
                        value1 = self.stack.pop()
                        value2 = self.stack.pop()
                        self.stack.append(value2 // value1)
                    case _:
                        raise SyntaxError(f"Instrução OP inválida: {self.input[0]}")
            case _:
                raise SyntaxError("Invalid instruction")

lexer = Lexer()
lexer.tokenizer("""
                PUSH 1
PUSH 2
OP +

PUSH 5
PUSH 1
OP -

OP *
POP
                """)

parser = Parser(lexer.tokens)
parser.parse()
