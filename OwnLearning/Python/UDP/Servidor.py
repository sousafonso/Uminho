import socket

class Servidor:
    def __init__(self, port=6013):
        # get the hostname
        self.host = ''  # bind to all available interfaces
        self.port = port  # initiate port no above 1024
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # get instance
        # look closely. The bind() function takes tuple as argument
        self.server_socket.bind((self.host, self.port))  # bind host address and port together
        # configure how many client the server can listen simultaneously
        self.server_socket.listen(2)
    
    def run(self):
        conn, address = self.server_socket.accept()  # accept new connection
        print("Connection from: " + str(address))
        while True:
            # receive data stream. it won't accept data packet greater than 1024 bytes
            data = conn.recv(1024).decode()
            if not data:
                # if data is not received break
                break
            conn.send(data.encode())  # send data to the client

        conn.close()  # close the connection

if __name__ == "__main__":
    servidor = Servidor()
    servidor.run()