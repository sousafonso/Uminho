package Ficha4;
import java.util.concurrent.locks.*;
import java.util.concurrent.locks.ReentrantLock;

class Agreement {
    private final int N;
    private Lock l = new ReentrantLock();
    private Condition c = l.newCondition();

    private int ctr = 0; // contador de propostas
    private int res = Integer.MIN_VALUE; // resultado

    /**
     * Classe interna para guardar o resultado da proposta o que permite que o objeto seja imutável
     * e que o resultado seja atualizado de forma atómica
     */
    private static class Instance {
        int res = Integer.MIN_VALUE;
    }

    private Instance instance = new Instance();

    public Agreement(int n) {
        this.N = n;
    }

    public int propose (int value) throws InterruptedException {
        l.lock();
        try {
            Instance i = this.instance;
            i.res = Math.max(res, value); // atualiza o resultado para o máximo entre o valor atual e o valor proposto
            this.ctr++;
            if (this.ctr < N){ // se ainda não foram todas as propostas
                while (i == this.instance) { // enquanto a instância não for atualizada
                    c.await(); // espera pela próxima fase
                }
            } else {
                this.ctr = 0;
                i = new Instance();
                c.signalAll();
            }
            return my.res;
        } finally {
            l.unlock();
        }
    }
}
