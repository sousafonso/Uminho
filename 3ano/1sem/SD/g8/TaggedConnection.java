package g8;

import java.io.*;
import java.net.Socket;
import java.util.concurrent.*;
import java.util.concurrent.locks.*;

public class TaggedConnection implements AutoCloseable {

    private Lock lock_senders = new ReentrantLock();
    private Lock lock_receivers = new ReentrantLock();

    public static class Frame {
        public final int tag;
        public final byte[] data;

        public Frame(int tag, byte[] data) {
            this.tag = tag;
            this.data = data;
        }
    }

    private final FramedConnection connection;

    public TaggedConnection(Socket socket) throws IOException { // Ao fim ao cabo isto vai ser uma FramedConnection só que vai ser etiquetada
        this.connection = new FramedConnection(socket);
    }

    public void send(Frame frame) throws IOException {
        lock_senders.lock();
        try {
            connection.send(serializeFrame(frame));
        } finally {
            lock_senders.unlock();
        }
    }

    public void send(int tag, byte[] data) throws IOException {
        send(new Frame(tag, data));
    }

    public Frame receive() throws IOException {
        lock_receivers.lock();
        try {
            return deserializeFrame(connection.receive());
        } finally {
            lock_receivers.unlock();
        }
    }

    @Override
    public void close() throws IOException {
        connection.close();
    }

    // Converte um Frame em um array de bytes
    private byte[] serializeFrame(Frame frame) throws IOException {
        try (ByteArrayOutputStream baos = new ByteArrayOutputStream(); // ByteArrayOutputStreamé uma classe que implementa um buffer de saída de bytes
             DataOutputStream dos = new DataOutputStream(baos)) {
            dos.writeInt(frame.tag);
            dos.writeInt(frame.data.length);
            dos.write(frame.data);
            return baos.toByteArray();
        }
    }

    // Converte um array de bytes em um Frame que é um objeto que contém uma tag e um array de bytes
    private Frame deserializeFrame(byte[] data) throws IOException {
        try (ByteArrayInputStream bais = new ByteArrayInputStream(data);
             DataInputStream dis = new DataInputStream(bais)) {
            int tag = dis.readInt();
            int length = dis.readInt();
            byte[] frameData = new byte[length];
            dis.readFully(frameData);
            return new Frame(tag, frameData);
        }
    }
}

/*
 * A principal diferença entre TaggedConnection e FramedConnection é que TaggedConnection adiciona um nível de 
 * abstração ao FramedConnection ao introduzir o conceito de "tags" para os dados enviados e recebidos. 
 * Aqui estão as diferenças detalhadas:

Estrutura dos Dados:

FramedConnection envia e recebe dados como um array de bytes, sem qualquer metadado adicional.
TaggedConnection envia e recebe dados encapsulados em uma estrutura chamada Frame, que inclui um tag (um inteiro) além dos dados (byte[]).
Envio de Dados:

FramedConnection possui um método send(byte[] data) que envia diretamente os dados.
TaggedConnection possui métodos send(Frame frame) e send(int tag, byte[] data) que primeiro encapsulam 
os dados em um Frame antes de enviá-los.
Recebimento de Dados:

FramedConnection possui um método receive() que retorna diretamente os dados recebidos como um array de bytes.
TaggedConnection possui um método receive() que retorna um Frame, que contém tanto o tag quanto os dados.
Serialização e Desserialização:

TaggedConnection inclui métodos privados serializeFrame(Frame frame) e deserializeFrame(byte[] data) para 
converter entre Frame e byte[], enquanto FramedConnection lida apenas com arrays de bytes diretamente.

Em resumo, TaggedConnection é uma camada adicional sobre FramedConnection que permite associar um identificador (tag) aos dados enviados e recebidos, facilitando a identificação e o processamento dos dados em um nível mais alto.
 */