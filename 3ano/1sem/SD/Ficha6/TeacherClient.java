import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TeacherClient {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 12345)) {
            BufferedInputStream in = new BufferedInputStream(socket.getInputStream());
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            BufferedReader reader = new BufferedReader(new InputStreamReader(in));
            Scanner scanner = new Scanner(System.in);

            String serverResponse;

            System.out.println("Digite números inteiros para enviar ao servidor (ou 'exit' para sair):");

            while (true) {
                String input = scanner.nextLine();

                if (input.equalsIgnoreCase("exit")) {
                    break;
                }

                out.println(input);
                out.flush();

                serverResponse = reader.readLine();
                System.out.println("Servidor: " + serverResponse);
            }

            scanner.close();

            serverResponse = reader.readLine();

            System.out.println("Servidor (Média final): " + serverResponse);

        } catch (IOException e) {
            System.out.println("Erro ao conectar ao servidor: " + e.getMessage());
        }
    }
}
