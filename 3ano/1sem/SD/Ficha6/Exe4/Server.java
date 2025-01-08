package Exe4;

import java.io.*;
import java.net.*;
import java.util.concurrent.locks.*;

class Register {
    private int count;
    private long sum;
    Lock lock = new ReentrantLock();

    public Register() {
        this.count = 0;
        this.sum = 0;
    }

    void add (int num){
        lock.lock();
        try {
            sum += num;
            count++;
        } finally {
            lock.unlock();
        }
    }

    double average () {
        lock.lock();
        try {
            return (double) sum / count;
        } finally {
            lock.unlock();
        }
    }
}

class ClientHandler extends Thread {
    Socket socket;
    Register register;
    ClientHandler(Socket socket, Register register) {
        this.socket = socket;
        this.register = register;
    }

    public ClientHandler(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            int sum = 0;
            String line;

            while ((line = reader.readLine()) != null) {
                try {
                    int number = Integer.parseInt(line);
                    sum += number;
                    out.println("A soma atual é: " + sum);
                    register.add(number);
                    double average = register.average();
                    out.flush();
                } 
                catch (NumberFormatException e) {
                    out.println("Invalid number");
                }
            }

            out.println("A média é de: " + register.average());
            out.flush();
            socket.close();

        } catch (IOException ex) {
            System.out.println("Server exception: " + ex.getMessage());
            ex.printStackTrace();
        }
    }
}

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(12345);
            Register register = new Register();
            while (true) {
                Socket socket = serverSocket.accept();
                ClientHandler clientHandler = new ClientHandler(socket, register);
                clientHandler.start();
            }
        } catch (IOException e) {
            System.out.println("Erro ao iniciar o servidor: " + e.getMessage());
            e.printStackTrace();
        }
    }

    // private static class ClientHandler extends Thread {
    //     private Socket socket;

    //     public ClientHandler(Socket socket) {
    //         this.socket = socket;
    //     }

    //     public void run() {
    //         try (InputStream input = socket.getInputStream();
    //              BufferedReader reader = new BufferedReader(new InputStreamReader(input));
    //              OutputStream output = socket.getOutputStream();
    //              PrintWriter writer = new PrintWriter(output, true)) {

    //             String text;
    //             while ((text = reader.readLine()) != null) {
    //                 try {
    //                     int number = Integer.parseInt(text);
    //                     sum.addAndGet(number);
    //                     count.incrementAndGet();
    //                     double average = (double) sum.get() / count.get();
    //                     writer.println("Current average: " + average);
    //                 } catch (NumberFormatException e) {
    //                     writer.println("Invalid number");
    //                 }
    //             }
    //         } catch (IOException ex) {
    //             System.out.println("Server exception: " + ex.getMessage());
    //             ex.printStackTrace();
    //         }
    //     }
    // }
}
