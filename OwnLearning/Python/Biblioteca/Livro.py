class Livro:
    def __init__(self, titulo, autor, isbn):
        self.titulo = titulo
        self.autor = autor
        self.isbn = isbn
        self.disponivel = True

    def emprestar():
        if self.disponivel:
            self.disponivel = False
            return True
        return False

    def devolver():
        """Marca livro como disponível."""
        self.disponivel = True