/*
 * @description: Classe que implementa a interface de comunicação com o servidor.
 */

// BibliotecaCliente.java
import java.io.*;
import java.net.*;
import java.util.*;

public class BibliotecaCliente {
    private static Cliente cliente; // Instância da classe Cliente

    // Método para conectar ao servidor 
    public static void conectar(String host, int porta) throws IOException {
        cliente = new Cliente(host, porta);
    }

    // Método para autenticar o utilizador no servidor
    public static void autenticarUtilizador(String nome, String senha) throws IOException {
        cliente.autenticar(nome, senha);
    }

    // Método para armazenar um valor associado a uma chave
    public static void put(String key, byte[] value) throws IOException {
        cliente.put(key, value);
    }

    // Método para obter o valor associado a uma chave
    public static byte[] get(String key) throws IOException {
        return cliente.get(key);
    }

    // Método para fechar a conexão com o servidor
    public static void fecharConexao() throws IOException {
        cliente.fechar();
    }
}