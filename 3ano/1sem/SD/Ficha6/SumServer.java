import java.io.*;
import java.net.*;

public class SumServer {
    public static void main(String[] args) {
        int port = 12345; // Porta para escutar conexões

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Servidor de somas iniciado na porta " + port);

            while (true) {
                try (Socket clientSocket = serverSocket.accept()) {
                    System.out.println("Cliente conectado.");

                    BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); // buffer de entrada para receber dados do cliente neste caso sao os numeros
                    PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true); // buffer de saida para enviar dados ao cliente com a media

                    int sum = 0;
                    int count = 0;
                    String line;

                    // Recebe números até EOF (end of file)
                    while ((line = in.readLine()) != null) {
                        try {
                            int number = Integer.parseInt(line);
                            sum += number;
                            count++;
                            out.println("Soma atual: " + sum);
                        } catch (NumberFormatException e) {
                            out.println("Entrada inválida.");
                        }
                    }

                    // Envia a média dos números recebidos
                    if (count > 0) {
                        double average = (double) sum / count;
                        out.println("Média dos números: " + average);
                    } else {
                        out.println("Nenhum número recebido.");
                    }

                    System.out.println("Cliente desconectado.");
                } catch (IOException e) {
                    System.out.println("Erro ao comunicar com o cliente: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Erro ao iniciar o servidor: " + e.getMessage());
        }
    }
}
