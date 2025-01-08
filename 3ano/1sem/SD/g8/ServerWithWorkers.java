package g8;

import java.net.ServerSocket;
import java.net.Socket;

import static g8.TaggedConnection.Frame;

public class ServerWithWorkers {
    final static int WORKERS_PER_CONNECTION = 3;

    public static void main(String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(12345);

        while(true) {
            Socket s = ss.accept();
            TaggedConnection c = new TaggedConnection(s);

            Runnable worker = () -> {
                try (c) {
                    for (;;) { // for (;;) é a mesma coisa que while(true)
                        Frame frame = c.receive();
                        int tag = frame.tag;
                        String data = new String(frame.data);
                        if (frame.tag == 0)
                            System.out.println("Got one-way: " + data);
                        else if (frame.tag % 2 == 1) {  // se a tag for ímpar então responde com a string em maiúsculas
                            System.out.println("Replying to: " + data);
                            c.send(frame.tag, data.toUpperCase().getBytes());
                        } else { // se a tag for par então envia a string letra a letra
                            for (int i = 0; i < data.length(); ++i) {
                                String str = data.substring(i, i+1); // substring(i, i+1) retorna a string que começa na posição i e termina na posição i+1
                                System.out.println("Streaming: " + str);
                                c.send(tag, str.getBytes());
                                Thread.sleep(100);
                            }
                            c.send(tag, new byte[0]);
                        }
                    }
                } catch (Exception ignored) { }
            };

            for (int i = 0; i < WORKERS_PER_CONNECTION; ++i) // cria #WORKERS_PER_CONNECTION threads para cada conexão, neste caso são criadas 3 threads
                new Thread(worker).start();
        }

    }
}
