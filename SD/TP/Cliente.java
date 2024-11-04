// Cliente.java
import java.io.*;
import java.net.*;

public class Cliente {
    private Socket socket;
    private DataInputStream entrada;
    private DataOutputStream saida;

    public Cliente(String host, int porta) throws IOException {
        this.socket = new Socket(host, porta); // Conecta ao servidor
        this.entrada = new DataInputStream(socket.getInputStream()); // Cria o canal de entrada
        this.saida = new DataOutputStream(socket.getOutputStream()); // Cria o canal de saída
    }

    // Método para autenticar o utilizador no servidor
    public void autenticar(String nome, String senha) throws IOException {
        saida.writeUTF(nome);
        saida.writeUTF(senha);
        String resposta = entrada.readUTF();
        System.out.println("Resposta do servidor: " + resposta);
    }

    // Método para armazenar um valor associado a uma chave
    public void put(String key, byte[] value) throws IOException {
        saida.writeUTF("PUT");
        saida.writeUTF(key);
        saida.writeInt(value.length);
        saida.write(value);
        System.out.println("Resposta do servidor: " + entrada.readUTF());
    }

    // Método para obter o valor associado a uma chave
    public byte[] get(String key) throws IOException {
        saida.writeUTF("GET");
        saida.writeUTF(key);
        int tamanho = entrada.readInt();
        if (tamanho != -1) {
            byte[] valor = new byte[tamanho];
            entrada.readFully(valor);
            return valor;
        } else {
            System.out.println("Chave não encontrada.");
            return null;
        }
    }

    // Método para fechar a conexão com o servidor
    public void fechar() throws IOException {
        entrada.close();
        saida.close();
        socket.close();
    }
}