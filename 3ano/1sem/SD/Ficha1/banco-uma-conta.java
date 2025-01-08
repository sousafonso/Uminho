import java.lang.Runnable;
import java.lang.Thread;
import java.util.concurrent.locks.ReentrantLock;

 // EXERCÍCIO 2
class Bank {

  private static class Account {
    private int balance;

    Account(int balance) {
      this.balance = balance;
    }

    // synchronized porque estamos a usar um monitor implícito, ou seja, o objeto Account
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
    return savings.balance(); // get the balance
  }

  // Deposit
  boolean deposit(int value) {
    return savings.deposit(value); // set the balance
  }
}

class DepositTask implements Runnable {
  private final Bank bank;
  private final int amount;
  private final int times;

  public DepositTask(Bank bank, int amount, int times) {
    this.bank = bank;
    this.amount = amount; // neste caso será 100 * 1000 = 100000
    this.times = times; // neste caso serão 1000 depósitos
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

    System.out.println("Valor esperado: " + (N * I * V)); 

    Bank bank = new Bank();
    Thread[] threads = new Thread[N];

    for (int i = 0; i < N; i++) {
      threads[i] = new Thread(new DepositTask(bank, V, I)); // para cada thread, o valor a depositar é 100 e o número de depósitos é 1000
    }

    for (int i = 0; i < N; i++) {
      threads[i].start();
    }

    for (int i = 0; i < N; i++) {
      threads[i].join();
    }

    System.out.println("Saldo final: " + bank.balance()); 
  }
}