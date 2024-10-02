import java.util.concurrent.locks.*;;

public class BancoMultiplasContas {

    private static class Account {
        private int balance;
        Account (int balance) { this.balance = balance; }
        int balance () { return balance; }
        boolean deposit (int value) {
            balance += value;
            return true;
        }
        boolean withdraw (int value) {
            if (value > balance)
                return false;
            balance -= value;
            return true;
        }
    }

    // Bank slots and vector of accounts
    private final int slots;
    private Account[] av;
    private  Lock l = new ReentrantLock();

    public BancoMultiplasContas (int n) {
        slots=n;
        av=new Account[slots];
        for (int i=0; i<slots; i++)
            av[i]=new Account(0);
    }


    // Account balance
    public int balance (int id) {
        if (id < 0 || id >= slots)
                return 0;
                
        l.lock();

        try{
            return av[id].balance();
        } finally{
            l.unlock();
        }
    }

    // Deposit
    /*
     * Aqui usamos lock para garantir que apenas uma thread por vez possa acessar ao método deposit
     * isto é, garantir que apenas uma thread por vez possa fazer um depósito para evitar que duas threads
     * façam um depósito ao mesmo tempo
     */
    public boolean deposit (int id, int value) {
        if (id < 0 || id >= slots)
            return false;

        l.lock();
        try {
            return av[id].deposit(value);
        } finally {
            l.unlock();
        }
    }

    // Withdraw; fails if no such account or insufficient balance
    /*
     * Aqui usamos lock para garantir que apenas uma thread por vez possa acessar ao método withdraw
     * isto é, garantir que apenas uma thread por vez possa fazer um levantamento para evitar que duas threads
     * façam um levantamento ao mesmo tempo e que uma delas não tenha saldo suficiente para fazer o levantamento
     */
    public boolean withdraw (int id, int value) {
        if (id < 0 || id >= slots)
            return false;

        l.lock();
        try{
            return av[id].withdraw(value);
        } finally {
            l.unlock();
        }
    }

    // Transfer
    public boolean transfer (int from, int to, int value) {
        if (from < 0 || from >= slots || to < 0 || to >= slots)
            return false;

        l.lock();
        try{
            if (av[from].withdraw(value)) {
                av[to].deposit(value);
                return true;
            }
            return false;
        } finally {
            l.unlock();
        }
    }

    // TotalBalance
    public int totalBalance () {
        int total=0;
        l.lock();
        try{
            for (int i=0; i<slots; i++)
                total+=av[i].balance();
        } finally {
            l.unlock();
        }
        return total;
    }
}

/*

EXERCICIO 3
 * import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BancoMultiplasContas {
    private final Conta[] av;
    private final Lock[] locks;
    private final int slots;

    public BancoMultiplasContas(int n) {
        this.slots = n;
        this.av = new Conta[n];
        this.locks = new ReentrantLock[n];
        for (int i = 0; i < n; i++) {
            av[i] = new Conta();
            locks[i] = new ReentrantLock();
        }
    }

    // Transfer
    public boolean transfer(int from, int to, int value) {
        if (from < 0 || from >= slots || to < 0 || to >= slots)
            return false;

        Lock firstLock = locks[Math.min(from, to)];
        Lock secondLock = locks[Math.max(from, to)];

        firstLock.lock();
        secondLock.lock();
        try {
            if (av[from].withdraw(value)) {
                av[to].deposit(value);
                return true;
            }
            return false;
        } finally {
            secondLock.unlock();
            firstLock.unlock();
        }
    }

    // Outros métodos...

    private class Conta {
        private int saldo;

        public boolean withdraw(int value) {
            if (saldo >= value) {
                saldo -= value;
                return true;
            }
            return false;
        }

        public void deposit(int value) {
            saldo += value;
        }
    }
}

EXPLICAÇÃO
1.Array de bloqueios: Criamos um array de bloqueios (locks), onde cada conta tem seu próprio bloqueio.
2.Ordem de bloqueio: No método transfer, adquirimos os bloqueios na ordem dos índices (Math.min(from, to) e Math.max(from, to)) para evitar deadlocks.
3.Bloqueio e desbloqueio: Adquirimos os bloqueios antes de realizar a transferência e os liberamos no bloco finally.
 */
