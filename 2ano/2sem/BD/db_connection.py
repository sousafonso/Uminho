import mysql.connector
from mysql.connector import Error

def create_connection():
    try:
        connection = mysql.connector.connect(
            host='localhost',
            database='AgenciaSemProvas',
            user='root',  # substitua pelo seu usuário do MySQL
            password='fsanches'  # substitua pela sua senha do MySQL
        )
        if connection.is_connected():
            print("Conexão com o MySQL foi estabelecida com sucesso")
            return connection
    except Error as e:
        print(f"Erro ao conectar ao MySQL: {e}")
        return None
