import oracledb
from pymongo import MongoClient

# Configurações de conexão
oracle_dsn = "localhost/orclp1"  # Atualize com os seus dados Oracle
oracle_user = "usuario"
oracle_password = "senha"

mongo_uri = "mongodb://localhost:27017"
mongo_db_name = "restaurante_db"
mongo_collection_name = "restaurantes"

# Conectando ao Oracle
conn_oracle = oracledb.connect(user=oracle_user, password=oracle_password, dsn=oracle_dsn)
cursor = conn_oracle.cursor()

# Conectando ao MongoDB
client = MongoClient(mongo_uri)
db = client[mongo_db_name]
collection = db[mongo_collection_name]

# Extraindo dados das tabelas Oracle e montando documentos MongoDB

# Consultas básicas para extrair dados
cursor.execute("SELECT * FROM RESTAURANTE")
restaurantes = {row[0]: {"_id": row[0], "nome": row[1], "localizacao": row[2], "telefone": row[3]} for row in cursor}

cursor.execute("SELECT * FROM CATEGORIA")
categorias = {row[0]: row[1] for row in cursor}

cursor.execute("SELECT * FROM PRATO")
pratos = {}
for row in cursor:
    pratos.setdefault(row[3], []).append({
        "id_prato": row[0],
        "nome": row[1],
        "preco": float(row[2]),
        "id_categoria": row[4],
        "categoria": categorias.get(row[4])
    })

cursor.execute("SELECT * FROM CLIENTE")
clientes = {row[0]: {
    "id_cliente": row[0],
    "nome": row[1],
    "email": row[2],
    "telefone": row[3],
    "endereco": row[4]
} for row in cursor}

cursor.execute("SELECT * FROM ENTREGADOR")
entregadores = {row[0]: {
    "id_entregador": row[0],
    "nome": row[1],
    "telefone": row[2],
    "veiculo": row[3]
} for row in cursor}

cursor.execute("SELECT * FROM PEDIDO")
pedidos = {}
for row in cursor:
    pedidos[row[0]] = {
        "id_pedido": row[0],
        "data_pedido": row[1].isoformat() if row[1] else None,
        "valor_total": float(row[2]) if row[2] else None,
        "id_cliente": row[3],
        "cliente": clientes.get(row[3]),
        "id_entregador": row[4],
        "entregador": entregadores.get(row[4]),
        "id_restaurante": row[5]
    }

cursor.execute("SELECT * FROM ITEM_PEDIDO")
for row in cursor:
    id_pedido = row[0]
    item = {
        "id_prato": row[1],
        "quantidade": int(row[2]) if row[2] else 1,
        "prato": None
    }
    # Buscar info do prato para o item
    for prato in pratos.get(pedidos[id_pedido]["id_restaurante"], []):
        if prato["id_prato"] == row[1]:
            item["prato"] = prato
            break

    pedidos[id_pedido].setdefault("itens", []).append(item)

# Compor documentos finais para inserir no MongoDB
for id_rest, rest in restaurantes.items():
    rest["pratos"] = pratos.get(id_rest, [])
    rest["pedidos"] = [pedido for pedido in pedidos.values() if pedido["id_restaurante"] == id_rest]

# Limpar coleção e inserir documentos
collection.delete_many({})
collection.insert_many(restaurantes.values())

# Fechar conexões
cursor.close()
conn_oracle.close()
client.close()

print("Migração concluída com sucesso.")
