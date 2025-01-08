import java.util.concurrent.locks.*;;

public class BancoMultiplasContas {

    private static class Account {
        private int balance;

        Account (int balance) { 
            this.balance = balance; 
        }

        int balance () { 
            return balance; 
        }

        boolean deposit (int value) {
            balance += value;
            return true; // se a operação for bem sucedida
        }
        boolean withdraw (int value) { // retirar dinheiro
            if (value > balance)
                return false;
            balance -= value;
            return true; // se a operação for bem sucedida
        }
    }

    // Bank slots and vector of accounts
    private final int slots;
    private Account[] av;
    private  Lock l = new ReentrantLock();

    public BancoMultiplasContas (int n) {
        slots=n;
        av=new Account[slots]; // Criação da estrutura para guardar as contas
        for (int i=0; i<slots; i++)
            av[i]=new Account(0); // inicialização do valor das contas
    }


    // Account balance
    public int balance (int id) {
        if (id < 0 || id >= slots) // o id da conta deve ser positivo e naturalmente nao deve ser superior ao numero de contas existentes no banco
                return 0; // é assumido que o id da conta é a sua posição no array
                
        l.lock();

        try{
            return av[id].balance(); // get the balance
        } finally{
            l.unlock();
        }
    }

    // Deposit
    /*
     * Aqui usamos lock para garantir que apenas uma thread por vez possa acessar ao método deposit
     * isto é, garantir que apenas uma thread por vez possa fazer um depósito para evitar que duas threads
     * façam um depósito ao mesmo tempo para evitar corridas
     */
    public boolean deposit (int id, int value) {
        if (id < 0 || id >= slots)
            return false;

        l.lock();
        try {
            return av[id].deposit(value); // depositar dinheiro 
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
        if (from < 0 || from >= slots || to < 0 || to >= slots) // verificação dos ids das contas de origem e destino
            return false;

        l.lock();
        try{
            if (av[from].withdraw(value)) { // se a conta origem tiver a quantia suficiente para transferir para a conta destino
                av[to].deposit(value);
                return true; // transferência bem sucedida
            }
            return false;
        } finally {
            l.unlock();
        }
    }

    // TotalBalance = soma de todos os saldos das contas
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
