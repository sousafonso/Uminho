import java.lang.Runnable;
import java.lang.Thread;
import java.util.concurrent.locks.ReentrantLock;

// EXERCICIO 3
// class Bank {

//   private static class Account {
//     private int balance;
//     private final ReentrantLock lock = new ReentrantLock();

//     Account(int balance) {
//       this.balance = balance;
//     }

//     int balance() {
//       lock.lock(); 
//       try {
//         return balance; 
//       } finally {
//         lock.unlock();
//       }
//     }

//     boolean deposit(int value) {
//       lock.lock(); 
//       try {
//         balance += value;
//         return true;
//       } finally {
//         lock.unlock();
//       }
//     }
//   }

//   // Our single account, for now
//   private Account savings = new Account(0);

//   // Account balance
//   public int balance() {
//     return savings.balance();
//   }

//   // Deposit
//   boolean deposit(int value) {
//     return savings.deposit(value);
//   }
// }

// class DepositTask implements Runnable {
//   private final Bank bank;
//   private final int amount;
//   private final int times;

//   public DepositTask(Bank bank, int amount, int times) {
//     this.bank = bank;
//     this.amount = amount;
//     this.times = times;
//   }

//   public void run() {
//     for (int i = 0; i < times; i++) {
//       bank.deposit(amount);
//     }
//   }
// }

// class Main {
//   public static void main(String[] args) throws InterruptedException {
//     final int N = 10; // Número de threads
//     final int I = 1000; // Número de depósitos por thread
//     final int V = 100; // Valor de cada depósito

//     Bank bank = new Bank();
//     Thread[] threads = new Thread[N];

//     for (int i = 0; i < N; i++) {
//       threads[i] = new Thread(new DepositTask(bank, V, I));
//     }

//     for (int i = 0; i < N; i++) {
//       threads[i].start();
//     }

//     for (int i = 0; i < N; i++) {
//       threads[i].join();
//     }

//     System.out.println("Saldo final: " + bank.balance());
//     System.out.println("Valor esperado: " + (N * I * V));
//   }
// }

/*
 * 1. ReentrantLock: Adicionei um ReentrantLock à classe Account para controlar o acesso aos métodos balance e deposit.
2. Métodos balance e deposit: Usei lock.lock() antes de acessar ou modificar o saldo e lock.unlock() no bloco finally para garantir que o bloqueio seja sempre liberado, mesmo se uma exceção for lançada.
3. Restante do Código: O restante do código permanece o mesmo, garantindo que 10 threads façam 1000 depósitos de 100 na conta compartilhada.
 */


 // EXERCÍCIO 2
class Bank {

  private static class Account {
    private int balance;

    Account(int balance) {
      this.balance = balance;
    }

    synchronized int balance() {
      return balance;
    }

    synchronized boolean deposit(int value) {
      balance += value;
      return true;
    }
  }

  // Our single account, for now
  private Account savings = new Account(0);

  // Account balance
  public int balance() {
    return savings.balance();
  }

  // Deposit
  boolean deposit(int value) {
    return savings.deposit(value);
  }
}

class DepositTask implements Runnable {
  private final Bank bank;
  private final int amount;
  private final int times;

  public DepositTask(Bank bank, int amount, int times) {
    this.bank = bank;
    this.amount = amount;
    this.times = times;
  }

  public void run() {
    for (int i = 0; i < times; i++) {
      bank.deposit(amount);
    }
  }
}

class Main {
  public static void main(String[] args) throws InterruptedException {
    final int N = 10; // Número de threads
    final int I = 1000; // Número de depósitos por thread
    final int V = 100; // Valor de cada depósito

    Bank bank = new Bank();
    Thread[] threads = new Thread[N];

    for (int i = 0; i < N; i++) {
      threads[i] = new Thread(new DepositTask(bank, V, I));
    }

    for (int i = 0; i < N; i++) {
      threads[i].start();
    }

    for (int i = 0; i < N; i++) {
      threads[i].join();
    }

    System.out.println("Saldo final: " + bank.balance()); 
    System.out.println("Valor esperado: " + (N * I * V)); 
  }
}