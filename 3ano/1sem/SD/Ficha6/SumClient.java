import java.io.*;
import java.net.*;
import java.util.Scanner;

public class SumClient {
    public static void main(String[] args) {
        String host = "localhost"; // Endereço do servidor
        int port = 12345; // Porta do servidor

        try (Socket socket = new Socket(host, port)) {
            System.out.println("Conectado ao servidor de somas.");

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream())); // buffer de entrada para receber dados do servidor neste caso a media
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true); // buffer de saida para enviar dados ao servidor com os numeros
            Scanner scanner = new Scanner(System.in);

            String serverResponse;

            // Enviar números para o servidor
            System.out.println("Digite números inteiros para enviar ao servidor (ou 'exit' para sair):");

            while (true) {
                String input = scanner.nextLine();
                
                if (input.equalsIgnoreCase("exit")) {
                    break;
                }

                // Enviar número para o servidor
                out.println(input);

                // Receber e mostrar a resposta do servidor
                serverResponse = in.readLine();
                System.out.println("Servidor: " + serverResponse);
            }

            // Fechar o scanner e aguardar a média final do servidor
            scanner.close();
            serverResponse = in.readLine();
            System.out.println("Servidor (Média final): " + serverResponse);

        } catch (IOException e) {
            System.out.println("Erro ao conectar ao servidor: " + e.getMessage());
        }
    }
}
