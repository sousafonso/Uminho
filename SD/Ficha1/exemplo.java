class exemplo extends Thread {
    public void run(){
        for (long l = 0; l < 1L << 32; l++);
        System.out.println("Na thread 1");
    }
}

// é mais versatil
class MyRunnable extends Runnable {
    public void run(){
        for (long l = 0; l < 1L << 32; l++);
        System.out.println("Na thread 2");
    }
}

class Main {
    public static void main(String[] args) throws InterruptedException{
        Thread t = new exemplo();
        // nao fazer as seguintes coisas
        // MyRunnable r = new MyRunnable();
        // Thread t3 = new Thread(r);
        // Thread t4 = new Thread(r);

        // mas sim
        Thread t2 = new Thread(new MyRunnable()); // para nao partilhar o objecto r entre as duas threads

        // t.run() <-- nunca se faz isto

        t.start();
        t2.start();
        System.out.println("Na main");
        t.join();
        t2.join();
        System.out.println("No fim");
    }
}