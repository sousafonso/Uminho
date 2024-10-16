package Ficha4;

import java.util.concurrent.locks.*;
import java.util.concurrent.locks.ReentrantLock;

class Barrier {
    private Lock l = new ReentrantLock();
    private Condition c = l.newCondition();

    private int contador = 0;
    private final int N;
    private int returned = 0;
    private boolean open = false; // conceito de barreira aberta ou fechada

    public Barrier(int N) {
        this.N = N;
    }

    public void await() throws InterruptedException {
        l.lock();
        try {
            while (open) { // se existir uma thread adiantada, espera que todas as outras cheguem
                c.await();
            }

            contador++;
            if (contador == N) {
                c.signalAll();
                open = true;
            }

            while (contador < N) {
                c.await();
            }

            returned++;

            if (returned == N) {
                contador = 0;
                returned = 0;
                open = false;
                c.signalAll();
            }
        } finally {
            l.unlock();
        }
    }
}