package Exe3;

import java.io.*;
import java.net.*;

class ClientHandler extends Thread {
    Socket socket;
    ClientHandler(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            int sum = 0;
            int count = 0;
            String line;

            while ((line = in.readLine()) != null) {
                try {
                    int number = Integer.parseInt(line);
                    sum += number;
                    count++;
                    out.println("Soma atual: " + sum);
                    out.flush();
                } catch (NumberFormatException e) {
                    out.println("Entrada inválida.");
                    out.flush();
                }
            }

            if (count > 0) {
                double average = (double) sum / count;
                out.println("Média dos números: " + average);
                socket.close();
            } else {
                out.println("Nenhum número recebido.");
                socket.close();
            }
        } catch (IOException e) {
            System.out.println("Erro ao processar a conexão: " + e.getMessage());
        }
    }
}

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(12345);

            while (true) {
                Socket socket = serverSocket.accept();
                ClientHandler clientHandler = new ClientHandler(socket);
                clientHandler.start();
            }
        } catch (IOException e) {
            System.out.println("Erro ao iniciar o servidor: " + e.getMessage());
            e.printStackTrace();
        }
    }
}