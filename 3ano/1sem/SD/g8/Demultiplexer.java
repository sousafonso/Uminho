package g8;
import java.io.*;
import java.net.Socket;
import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.locks.*;

import g8.TaggedConnection;

public class Demultiplexer implements AutoCloseable {
    private final TaggedConnection connection;
    private final Lock lock = new ReentrantLock();
    private final Map<Integer, Entry> map = new HashMap<>();


    private static class Entry { // Entry que 
        final Condition condition = new ReentrantLock().newCondition();
        final Deque<byte[]> queue = new ArrayDeque<>();
    }

    public Demultiplexer(TaggedConnection connection) throws IOException {
        this.connection = connection;
    }

    public void start() {
        new Thread(() -> {
            try {
                for (;;) {
                    TaggedConnection.Frame frame = connection.receive();
                    int tag = frame.tag;
                    byte[] data = frame.data;

                    lock.lock();
                    Entry entry = map.get(tag);
                    if (entry != null) {
                        entry.queue.add(data);
                        entry.condition.signal();
                    }
                    lock.unlock();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }

    public void send(TaggedConnection.Frame frame) throws IOException {
        connection.send(frame);
    }

    public void send(int tag, byte[] data) throws IOException {
        send(new TaggedConnection.Frame(tag, data));
    }

    public byte[] receive(int tag) throws IOException, InterruptedException {
        lock.lock();
        try {
            Entry entry = map.computeIfAbsent(tag, k -> new Entry()); // Se a chave não existir, cria uma nova entrada no map
            while (entry.queue.isEmpty()) {
                entry.condition.await();
            }
            return entry.queue.poll();
        } finally {
            lock.unlock();
        }
    }

    @Override
    public void close() throws IOException {
        connection.close();
    }
}
