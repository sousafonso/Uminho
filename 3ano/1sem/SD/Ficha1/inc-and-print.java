import java.lang.Runnable;
import java.lang.Thread;

class Increment implements Runnable {
    private final long I;

    public Increment(long I) {
        this.I = I;
    }

    public void run() {
        for (long i = 0; i < I; i++) {
            System.out.println(i + 1);
        }
    }
}

class Main {
    public static void main(String[] args) throws InterruptedException {
        final int N = 10; // Número de threads
        final long I = 100; // Número até onde cada thread deve contar

        Thread[] a = new Thread[N];

        // ciclo para criar todas as threads
        for (int i = 0; i < N; i++) {
            a[i] = new Thread(new Increment(I));
        }

        // ciclo para iniciar todas as threads
        for (int i = 0; i < N; i++) {
            a[i].start();
        }

        // ciclo para esperar que todas as threads terminem
        for (int i = 0; i < N; i++) {
            a[i].join();
        }

        System.out.println("fim");
    }
}

/**
 * 1.Increment Class: Adicionei um construtor para aceitar o valor I como parâmetro.
    2.Main Class: Defini N como 10 e I como 100 diretamente no código.
    3.Thread Creation: Passei I para o construtor de Increment ao criar cada thread.
    4.Final Message: Após todas as threads terminarem, o programa imprime "fim".
 */