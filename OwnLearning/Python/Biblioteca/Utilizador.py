from Biblioteca import *

class Utilizador:
    def __init__(self, nome, id_utilizador):
        self.nome = nome
        self.id_utilizador = id_utilizador
        self.livros_emprestados = []

    def adicionar_emprestimo(self, livro):
        self.livros_emprestados.append(livro)

    def remover_emprestimo(self, livro):
        self.livros_emprestados.remove(livro)