import Livro, Utilizador 

class Biblioteca:

    LIMITE_EMPRESTIMOS = 3

    def __init__(self):
        self.catalogo = {}  # ISBN -> Livro
        self.utilizadores = {}  # ID -> Utilizador

    def adicionar_livro(self, livro):
        """Adiciona livro ao catálogo."""
        if livro.isbn in self.catalogo:
            print(f"Livro com ISBN {livro.isbn} já existe")
            return False
        
        self.catalogo[livro.isbn] = livro
        print(f"Livro '{livro.titulo}' adicionado com sucesso")
        return True
    
    def remover_livro(self, isbn):
        if isbn not in self.catalogo:
            print(f"Livro com ISBN {isbn} não encontrado")
            return False
        
        livro = self.catalogo[isbn]
        if not livro.disponivel:
            print(f"Não é possível remover. Livro está emprestado")
            return False
        
        del self.catalogo[isbn]
        print(f"Livro removido com sucesso")
        return True
    
    def registar_usuario(self, utilizador):
        if utilizador.id_utilizador in self.utilizadores:
            print(f"O utilizador com o id {utilizador.id_utilizador} já existe")
            return False
        
        self.utilizadores[utilizador.id_utilizador] = {utilizador}

        print(f"Utilizador '{utilizador.nome}' registado com sucesso")
        return True
    
    def emprestar_livro(self, isbn, id_utilizador):
        if not isbn in self.catalogo:
            print(f"Livro {isbn} não existe")
            return False
        if not id_utilizador in self.utilizadores:
            print(f"Utilizador {id_utilizador} não existe")
            return False
        
        utilizador = self.utilizadores[id_utilizador]
        livro = self.catalogo[isbn]
        
        # Verificar limite de empréstimos
        if len(utilizador.livros_emprestados) >= self.LIMITE_EMPRESTIMOS:
            print(f"Limite de {self.LIMITE_EMPRESTIMOS} empréstimos atingido")
            return False
        
        # Verificar disponibilidade
        if not livro.disponivel:
            print("Livro não está disponível")
            return False
        
        # Realizar empréstimo
        livro.emprestar()

        utilizador.adicionar_emprestimo(livro)
        print(f"Livro '{livro.titulo}' emprestado a {utilizador.nome}")
        return True
    
    def devolver_livro(self, isbn, id_utilizador):
        if not isbn in self.catalogo:
            print(f"Livro {isbn} não existe")
            return False
        
        if not id_utilizador in self.utilizadores:
            print(f"Utilizador {id_utilizador} não existe")
            return False
        
        if livro not in utilizador.livros_emprestados:
            print("Este utilizador não tem este livro emprestado")
            return False
        
        utilizador = self.utilizadores[id_utilizador]
        livro = self.catalogo[isbn]

        utilizador.remover_emprestimo(livro)
        livro.devolver()

        return True
    
    def pesquisar_livro(self, termo):
        """Pesquisa livros por título, autor ou ISBN."""
        resultados = []
        termo_lower = termo.lower()
        
        for livro in self.catalogo.values():
            if (termo_lower in livro.titulo.lower() or 
                termo_lower in livro.autor.lower() or 
                termo in livro.isbn):
                resultados.append(livro)
        
        if resultados:
            print(f"\n=== Resultados da Pesquisa ({len(resultados)}) ===")
            for livro in resultados:
                print(livro)
        else:
            print("Nenhum livro encontrado")
        
        return resultados

    def listar_disponiveis(self):
        disponiveis = []
        for livro in self.catalogo.values():
            if livro.disponivel:
                disponiveis.append(livro)

        if disponiveis:
            print(f"\n=== Livros Disponíveis ({len(disponiveis)}) ===")
            for livro in disponiveis:
                print(livro)
        else:
            print("Nenhum livro disponível")
        
        return disponiveis