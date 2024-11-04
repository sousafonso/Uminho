// Servidor.java
import java.io.*;
import java.net.*;
import java.util.*;
import java.util.concurrent.*;

public class Servidor {
    private static final Map<String, byte[]> armazenamento = new ConcurrentHashMap<>(); // Simula uma base de dados
    private static final Set<String> utilizadores = ConcurrentHashMap.newKeySet(); // Simula uma base de dados de utilizadores
    private static final int MAX_SESSOES = 5; // Exemplo de limite de conexões concorrentes
    private static final Semaphore semaphore = new Semaphore(MAX_SESSOES); // Semáforo para controlar o número de sessões

    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(12345)) {
            System.out.println("Servidor iniciado na porta 12345...");
            while (true) {
                Socket clienteSocket = serverSocket.accept();
                if (semaphore.tryAcquire()) {
                    new Thread(new AtendedorDeCliente(clienteSocket)).start();
                } else {
                    clienteSocket.close();
                    System.out.println("Conexão recusada: limite de sessões atingido.");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /*
     * Socket: Cada instância da classe AtendedorDeCliente recebe um Socket, que representa a conexão com um cliente específico.
        Método run(): Contém a lógica de autenticação do cliente e o processamento de comandos recebidos. Ele escuta continuamente as entradas do cliente e executa ações como operações PUT e GET.
        Métodos auxiliares:
            put(String key, byte[] value): Adiciona ou atualiza um par chave-valor na memória do servidor.
            get(String key): Retorna o valor associado a uma chave específica, ou null se não existir.
     */
    static class AtendedorDeCliente implements Runnable {
        private final Socket socket;

        AtendedorDeCliente(Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {
            try (DataInputStream entrada = new DataInputStream(socket.getInputStream());
                 DataOutputStream saida = new DataOutputStream(socket.getOutputStream())) {

                // Autenticação do cliente
                String usuario = entrada.readUTF();
                String senha = entrada.readUTF();
                if (!autenticarUsuario(usuario, senha)) {
                    saida.writeUTF("Autenticação falhou.");
                    return;
                }
                saida.writeUTF("Autenticação bem-sucedida.");

                // Processamento de comandos
                while (true) {
                    String comando = entrada.readUTF();
                    switch (comando) {
                        case "PUT":
                            String chave = entrada.readUTF();
                            int tamanhoValor = entrada.readInt();
                            byte[] valor = new byte[tamanhoValor];
                            entrada.readFully(valor);
                            put(chave, valor);
                            saida.writeUTF("PUT OK");
                            break;
                        case "GET":
                            chave = entrada.readUTF();
                            byte[] resultado = get(chave);
                            if (resultado != null) {
                                saida.writeInt(resultado.length);
                                saida.write(resultado);
                            } else {
                                saida.writeInt(-1);
                            }
                            break;
                        // Implementar outras operações conforme necessário
                        default:
                            saida.writeUTF("Comando desconhecido.");
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                semaphore.release();
                try {
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        private synchronized void put(String key, byte[] value) {
            armazenamento.put(key, value);
        }

        private synchronized byte[] get(String key) {
            return armazenamento.get(key);
        }
    }

    // este método é sincronizado para evitar condições de corrida ao acessar a lista de utilizadores
    private static boolean autenticarUsuario(String nome, String senha) {
        // Lógica simples de autenticação (exemplo)
        return utilizadores.contains(nome + senha);
    }

    // este método é sincronizado para evitar condições de corrida ao acessar a lista de utilizadores  
    public static void registarUsuario(String nome, String senha) {
        utilizadores.add(nome + senha);
    }
}
