import socket

class Cliente:
    def __init__(self, host='localhost', port=6013):
        self.host = host  # as both code is running on same pc
        self.port = port  # socket server port number
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # instantiate
    
    def connect(self):
        self.client_socket.connect((self.host, self.port))  # connect to the server
    
    def run(self):
        message = input(" -> ")  # take input

        while message.lower().strip() != 'fechar':
            self.client_socket.send(message.encode())  # send message
            data = self.client_socket.recv(1024).decode()  # receive response

            print('Received from server: ' + data)  # show in terminal

            message = input(" -> ")  # again take input

        self.client_socket.close()  # close the connection

if __name__ == "__main__":
    cliente = Cliente()
    cliente.connect()
    cliente.run()

