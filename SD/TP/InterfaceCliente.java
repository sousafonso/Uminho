/*
 * @description: Classe que implementa a interface do cliente.
 */

// InterfaceCliente.java
import java.io.*;
import java.util.*;

public class InterfaceCliente {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Digite o host do servidor: ");
            String host = scanner.nextLine();
            System.out.print("Digite a porta do servidor: ");
            int porta = Integer.parseInt(scanner.nextLine());

            BibliotecaCliente.conectar(host, porta);

            System.out.print("Digite o nome de usuário: ");
            String usuario = scanner.nextLine();
            System.out.print("Digite a senha: ");
            String senha = scanner.nextLine();
            BibliotecaCliente.autenticarUtilizador(usuario, senha);

            boolean executando = true;
            while (executando) {
                System.out.println("1. PUT\n2. GET\n3. Sair");
                System.out.print("Escolha uma opção: ");
                int opcao = Integer.parseInt(scanner.nextLine());

                switch (opcao) {
                    case 1:
                        System.out.print("Digite a chave: ");
                        String chave = scanner.nextLine();
                        System.out.print("Digite o valor: ");
                        String valor = scanner.nextLine();
                        BibliotecaCliente.put(chave, valor.getBytes());
                        break;
                    case 2:
                        System.out.print("Digite a chave: ");
                        chave = scanner.nextLine();
                        byte[] resultado = BibliotecaCliente.get(chave);
                        if (resultado != null) {
                            System.out.println("Valor: " + new String(resultado));
                        }
                        break;
                    case 3:
                        executando = false;
                        BibliotecaCliente.fecharConexao();
                        break;
                    default:
                        System.out.println("Opção inválida.");
                        break;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}