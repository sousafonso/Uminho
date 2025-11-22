import oracledb
from neo4j import GraphDatabase
import os 


def ler_tabela(cursor, tabela):
        cursor.execute(f"SELECT * FROM {tabela}")
        colunas = [col[0] for col in cursor.description]
        dados = []
        for linha in cursor.fetchall():
            dados.append(dict(zip(colunas, linha)))
        return dados
    
def criar_restaurantes(driver, restaurantes):
    with driver.session() as session:
        for r in restaurantes:
            session.run(
                """
                MERGE (res:Restaurante {id: $id})
                SET res.nome = $nome 
                """
                , id = r["ID_RESTAURANTE"], nome = r["NOME"]
            )

def criar_clientes(driver, clientes):
    with driver.session() as session:
        for c in clientes:
            session.run(
                """
                MERGE (cli:Cliente {id: $id})
                SET cli.nome = $nome 
                """
                , id = c["ID_CLIENTE"], nome = c["NOME"]
            )

def criar_pedidos(driver, pedidos):
    with driver.session() as session:
        for p in pedidos:
            # CRIAÇÃO DO NÓ PEDIDO
            session.run(
                """
                MERGE (ped:Pedido {id: $id})
                SET ped.valor = $valor
                """, 
                id = p["ID_PEDIDO"], valor = p["VALOR_TOTAL"]
            )

            # RELAÇÃO ENTRE PEDIDO E CLIENTE
            session.run(
                """
                MATCH (ped:Pedido {id: $id_pedido})
                MATCH (cli:Cliente {id: $id_cliente})
                MERGE (cli)-[:FEZ]->(ped)
                """,
                id_pedido = p["ID_PEDIDO"], id_cliente = p["ID_CLIENTE"]
            )

            # RELAÇÃO ENTRE PEDIDO E RESTAURANTE
            session.run(
                """
                MATCH (ped:Pedido {id: $id_pedido})
                MATCH (res:Restaurante {id: $id_restaurante})
                MERGE (ped)-[:REALIZADO_EM]->(res)
                """,
                id_pedido = p["ID_PEDIDO"], id_restaurante = p["ID_RESTAURANTE"]
            )

def main():
    print("A ligar ao oracle")
    NEO4J_URI = "bolt://localhost:7687"
    NEO4J_USER = "neo4j"
    NEO4J_PASSWORD = "afonsinho2004"

    conn = oracledb.connect(
        user="restaurant",
        password="restaurant2025",
        dsn="localhost/orclpdb1"
    )

    cursor = conn.cursor()
    driver = GraphDatabase.driver(NEO4J_URI, auth=(NEO4J_USER, NEO4J_PASSWORD))
    
    restaurantes = ler_tabela(cursor, "RESTAURANTE")
    print("Restaurantes lidos")
    criar_restaurantes(driver, restaurantes)
    clientes = ler_tabela(cursor, "CLIENTE")
    print("Clientes lidos")
    criar_clientes(driver, clientes)
    pedidos = ler_tabela(cursor, "PEDIDO")
    print("Pedidos lidos")
    criar_pedidos(driver, pedidos)

if __name__ == "__main__":
    main()