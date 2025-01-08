import pandas as pd
from db_connection import create_connection

def clear_tables():
    connection = create_connection()
    cursor = connection.cursor()
    cursor.execute("SET FOREIGN_KEY_CHECKS = 0")  # Desabilitar verificação de chave estrangeira
    cursor.execute("DROP TABLE Procedimento_Caso_Detetive")
    cursor.execute("DROP TABLE Caso_Detetive")
    cursor.execute("DROP TABLE Detetive")
    cursor.execute("DROP TABLE Caso")
    cursor.execute("DROP TABLE Cliente")
    cursor.execute("DROP TABLE Departamento")
    cursor.execute("DROP TABLE Procedimento")
    cursor.execute("SET FOREIGN_KEY_CHECKS = 1")  # Habilitar verificação de chave estrangeira novamente
    connection.commit()
    cursor.close()
    connection.close()

def populate_clientes(csv_file):
    connection = create_connection()
    cursor = connection.cursor()
    df = pd.read_csv(csv_file, delimiter=';')
    
    for _, row in df.iterrows():
        cursor.execute(
            "INSERT INTO Cliente (NIF, Nome, Codigo_Postal, Localidade, Rua, Numero_Porta, Data_Nascimento, Estado_Civil, Telemovel, eMail, Idade) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)",
            tuple(row)
        )
    connection.commit()
    cursor.close()
    connection.close()

def populate_departamentos(csv_file):
    connection = create_connection()
    cursor = connection.cursor()
    df = pd.read_csv(csv_file, delimiter=';')
    
    for _, row in df.iterrows():
        cursor.execute(
            "INSERT INTO Departamento (Id, Especializacao, Telemovel, eMail) VALUES (%s, %s, %s, %s)",
            tuple(row)
        )
    connection.commit()
    cursor.close()
    connection.close()

def populate_detetives(csv_file):
    connection = create_connection()
    cursor = connection.cursor()
    df = pd.read_csv(csv_file, delimiter=';')
    
    for _, row in df.iterrows():
        cursor.execute(
            "INSERT INTO Detetive (Numero_Mecanografico, Nome, Classificacao, Salario, Codigo_Postal, Localidade, Rua, Numero_Porta, Telemovel, eMail, Departamento) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s)",
            tuple(row)
        )
    connection.commit()
    cursor.close()
    connection.close()

# def populate_casos(csv_file):
#     connection = create_connection()
#     cursor = connection.cursor()
#     df = pd.read_csv(csv_file, delimiter=';')
    
#     for _, row in df.iterrows():
#         cursor.execute(
#             "INSERT INTO Caso (Numero, Descricao, Custo, Data_Inicio, Data_Fim, Estado, Cliente) VALUES (%s, %s, %s, %s, %s, %s, %s)",
#             tuple(row)
#         )
#     connection.commit()
#     cursor.close()
#     connection.close()

# def populate_procedimentos(csv_file):
#     connection = create_connection()
#     cursor = connection.cursor()
#     df = pd.read_csv(csv_file, delimiter=';')
    
#     for _, row in df.iterrows():
#         cursor.execute(
#             "INSERT INTO Procedimento (Id, Custo, Descricao) VALUES (%s, %s, %s)",
#             tuple(row)
#         )
#     connection.commit()
#     cursor.close()
#     connection.close()

# def populate_procedimento_caso(csv_file):
#     connection = create_connection()
#     cursor = connection.cursor()
#     df = pd.read_csv(csv_file, delimiter=';')
    
#     for _, row in df.iterrows():
#         cursor.execute(
#             "INSERT INTO Procedimento_Caso_Detetive (Custo_Total, Caso, Procedimento, Detetive) VALUES (%s, %s, %s, %s)",
#             tuple(row)
#         )
#     connection.commit()
#     cursor.close()
#     connection.close()

# def populate_caso_detetive(csv_file):
#     connection = create_connection()
#     cursor = connection.cursor()
#     df = pd.read_csv(csv_file, delimiter=';')
    
#     for _, row in df.iterrows():
#         cursor.execute(
#             "INSERT INTO Caso_Detetive (Caso, Detetive, Data_Inicio, Data_Fim) VALUES (%s, %s, %s, %s)",
#             tuple(row)
#         )
#     connection.commit()
#     cursor.close()
#     connection.close()