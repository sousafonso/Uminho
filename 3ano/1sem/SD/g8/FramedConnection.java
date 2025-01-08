package g8;

import java.io.*;
import java.util.concurrent.*;
import java.net.Socket;
import java.util.concurrent.locks.*;

public class FramedConnection implements AutoCloseable {
    private final Socket socket; // Socket é usado para comunicação entre processos em rede, abstratamente pode ser visto como um arquivo aberto para leitura e escrita
    private final DataInputStream in; // DataInputStream e DataOutputStream são usados para enviar e receber dados primitivos em formato binário respetivamente
    private final DataOutputStream out;
    private Lock lock_senders = new ReentrantLock(); // Lock é uma interface que define um mecanismo de sincronização que permite que apenas uma thread por vez execute um bloco de código
    private Lock lock_receivers = new ReentrantLock();

    public FramedConnection(Socket socket) throws IOException {
        this.socket = socket;
        this.in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
        this.out = new DataOutputStream(new BufferedOutputStream(socket.getOutputStream()));
    }

    public void send(byte[] data) throws IOException {
        lock_senders.lock();
        try {
            out.writeInt(data.length);
            out.write(data);
            out.flush();
        } finally {
            lock_senders.unlock();
        }
    }

    public byte[] receive() throws IOException {
        lock_receivers.lock();
        try {
            int length = in.readInt();
            byte[] data = new byte[length];
            in.readFully(data); // lê exatamente length bytes do stream de entrada
            return data;
        } finally {
            lock_receivers.unlock();
        }
    }

    @Override
    public void close() throws IOException {
        socket.close();
    }
}

/*
 * Explicação do Código
Construtor: Inicializa o Socket, DataInputStream e DataOutputStream.
Método send: Sincronizado para garantir que apenas uma thread por vez possa enviar dados. Escreve o comprimento dos dados seguido pelos próprios dados e, em seguida, chama flush para garantir que todos os dados sejam enviados.
Método receive: Sincronizado para garantir que apenas uma thread por vez possa receber dados. Lê o comprimento dos dados e, em seguida, lê os dados completos.
Método close: Fecha o Socket, o que também fecha os streams associados.
 */