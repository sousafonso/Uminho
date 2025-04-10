# Classe grafo para representaçao de grafos,
import math
from queue import Queue

#import networkx as nx  # biblioteca de tratamento de grafos necessária para desnhar graficamente o grafo
#import matplotlib.pyplot as plt  # idem

from Node import Node

# Constructor
# Methods for adding edges
# Methods for removing edges
# Methods for searching a graph
# BFS, DFS, A*, Greedy

class Graph:
    def __init__(self, directed=False):
        self.m_nodes = []  
        self.m_directed = directed
        self.m_graph = {}  
        self.m_h = {}  

    #################################
    #    escrever o grafo como string
    #################################
    def __str__(self):
        out = ""
        for key in self.m_graph.keys():
            out = out + "node" + str(key) + ": " + str(self.m_graph[key]) + "\n"
        return out

    ################################
    #   encontrar nodo pelo nome
    ################################

    def get_node_by_name(self, name):
        search_node = Node(name)
        for node in self.m_nodes:
            if node == search_node:
                return node
          
        return None

    ##############################3
    #   imprimir arestas
    ############################333333

    def imprime_aresta(self):
        listaA = ""
        lista = self.m_graph.keys()
        for nodo in lista:
            for (nodo2, custo) in self.m_graph[nodo]:
                listaA = listaA + nodo + " ->" + nodo2 + " custo:" + str(custo) + "\n"
        return listaA

    ################
    #   adicionar   aresta no grafo
    ######################

    def add_edge(self, node1, node2, weight):
        n1 = Node(node1)
        n2 = Node(node2)
        if (n1 not in self.m_nodes):
            n1_id = len(self.m_nodes)  # numeração sequencial
            n1.setId(n1_id)
            self.m_nodes.append(n1)
            self.m_graph[node1] = []
        else:
            n1 = self.get_node_by_name(node1)

        if (n2 not in self.m_nodes):
            n2_id = len(self.m_nodes)  # numeração sequencial
            n2.setId(n2_id)
            self.m_nodes.append(n2)
            self.m_graph[node2] = []
        else:
            n2 = self.get_node_by_name(node2)

        self.m_graph[node1].append((node2, weight)) 

        if not self.m_directed:
            self.m_graph[node2].append((node1, weight))

    #############################
    # devolver nodos
    ##########################

    def getNodes(self):
        return self.m_nodes

    #######################
    #    devolver o custo de uma aresta
    ##############3

    def get_arc_cost(self, node1, node2):
        custoT = math.inf
        a = self.m_graph[node1]  # lista de arestas para aquele nodo
        for (nodo, custo) in a:
            if nodo == node2:
                custoT = custo

        return custoT

    ##############################
    #  dado um caminho calcula o seu custo
    ###############################

    def calcula_custo(self, caminho):
        # caminho é uma lista de nodos
        teste = caminho
        custo = 0
        i = 0
        while i + 1 < len(teste):
            custo = custo + self.get_arc_cost(teste[i], teste[i + 1])
            i = i + 1
        return custo

       ################################################################################
    #     procura DFS (Depth First Search)
    ####################################################################################

    def procura_DFS(self, inicio, fim, path=[], visited=set()):
        path = path + [inicio]
        visited.add(inicio)
        if inicio == fim:
            return path
        if inicio not in self.m_graph: # se o nodo não pertence ao grafo
            return None
        for node in self.m_graph[inicio]:
            if node[0] not in visited:
                newpath = self.procura_DFS(node[0], fim, path, visited)
                if newpath:
                    return newpath
        return None
    
    ############################
    #  SOLUÇÃO DO PROFESSOR
    ############################

    def procura_DFS2(self, inicio, fim, path=[], visited=set()):
        path.append(inicio)
        visited.add(inicio)

        if inicio == fim:
            custo = self.calcula_custo(path)
            return path, custo
        for (adjacente, peso) in self.m_graph[inicio]:
            if adjacente not in visited:
                resultado = self.procura_DFS2(adjacente, fim, path, visited)
                if resultado is not None:
                    return resultado
        path.pop()
        return None
    
    #####################################################
    # Procura DFS  (Depth First Search) sem recursividade
    #####################################################

    def procura_DFS3(self, inicio, fim):
        stack = [(inicio, [inicio])]
        visited = set()

        while stack:
            (node, path) = stack.pop()
            if node in visited:
                continue
            if node == fim:
                return path
            visited.add(node)
            for (adjacente, peso) in self.m_graph.get(node, []):
                if adjacente not in visited:
                    stack.append((adjacente, path + [adjacente]))
        return None
    
    #####################################################
    # Procura BFS  (Breadth First Search)
    ######################################################
    def procura_BFS(self, inicio, fim):
        q = Queue()
        q.put([inicio]) # coloca o nodo inicial na fila
        while not q.empty():
            path = q.get() # obtem o caminho da fila
            node = path[-1] # obtem o ultimo nodo do caminho
            if node == fim: # se o nodo for o nodo final
                return path
            if node not in self.m_graph: # se o nodo não pertence ao grafo
                continue
            for neighbour in self.m_graph[node]: # para cada vizinho do nodo
                new_path = list(path) 
                new_path.append(neighbour[0]) # adiciona o vizinho ao caminho
                q.put(new_path) # coloca o novo caminho na fila
        return None
  
    ####################
    # funçãop  getneighbours, devolve vizinhos de um nó
    ##############################

    def getNeighbours(self, nodo):
        lista = []
        for (adjacente, peso) in self.m_graph[nodo]:
            lista.append((adjacente, peso))
        return lista

    ###########################
    # desenha grafo  modo grafico
    #########################

    def desenha(self):
        ##criar lista de vertices
        lista_v = self.m_nodes
        lista_a = []
        g = nx.Graph()
        for nodo in lista_v:
            n = nodo.getName()
            g.add_node(n)
            for (adjacente, peso) in self.m_graph[n]:
                lista = (n, adjacente)
                # lista_a.append(lista)
                g.add_edge(n, adjacente, weight=peso)

        pos = nx.spring_layout(g)
        nx.draw_networkx(g, pos, with_labels=True, font_weight='bold')
        labels = nx.get_edge_attributes(g, 'weight')
        nx.draw_networkx_edge_labels(g, pos, edge_labels=labels)

        plt.draw()
        plt.show()

    ####################################33
    #    add_heuristica   -> define heuristica para cada nodo 1 por defeito....
    ################################3

    def add_heuristica(self, n, estima):
        n1 = Node(n)
        if n1 in self.m_nodes:
            self.m_h[n] = estima



    ##########################################
    #    A* - To Do
    # RACIOCINIO
    # 1.  Inicializa-se o caminho com o nodo inicial
    # 2.  Enquanto o ultimo nodo do caminho for diferente do nodo final
    # 3.  Obtem-se o nodo
    # 4.  Obtem-se os vizinhos do nodo
    # 5.  Ordena-se os vizinhos por ordem crescente do peso para cada vizinho
    # 6.  Para cada vizinho calcula-se a heuristica
    # 7.  Se o vizinho não pertence ao caminho adiciona-se o vizinho ao caminho
    # 8.  Termina o ciclo
    ##########################################
    def procura_aStar(self, inicio, fim):
        caminho = []
        caminho.append(inicio)
        while caminho[-1] != fim:
            nodo = caminho[-1]
            vizinhos = self.getNeighbours(nodo)
            vizinhos.sort(key=lambda x: x[1])
            for (adjacente, peso) in vizinhos:
                if adjacente not in caminho:
                    caminho.append(adjacente)
                    break
        return caminho
        

    ###################################3
    # devolve heuristica do nodo
    ####################################

    def getH(self, nodo):
        if nodo not in self.m_h.keys():
            return 1000
        else:
            return (self.m_h[nodo])


    ##########################################
    #   Greedy - To Do
    # RACIOCINIO
    # 1.  Inicializa-se o caminho com o nodo inicial
    # 2.  Enquanto o ultimo nodo do caminho for diferente do nodo final
    # 3.  Obtem-se o nodo
    # 4.  Obtem-se os vizinhos do nodo
    # 5.  Ordena-se os vizinhos por ordem crescente do peso para cada vizinho
    # 7.  Se o vizinho não pertence ao caminho adiciona-se o vizinho ao caminho
    # 9.  Termina o ciclo
    ##########################################
    def greedy (self, inicio, fim):
        caminho = []
        caminho.append(inicio)
        while caminho[-1] != fim:
            nodo = caminho[-1]
            vizinhos = self.getNeighbours(nodo)
            vizinhos.sort(key=lambda x: x[1])
            for (adjacente, peso) in vizinhos:
                if adjacente not in caminho:
                    caminho.append(adjacente)
                    break
        return caminho

    




