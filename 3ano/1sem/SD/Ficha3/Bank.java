package Ficha3;

import java.util.*;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

class Bank {

    private static class Account {
        private int balance;
        public Object lock;
        Account(int balance) { this.balance = balance; }
        int balance() { return balance; }
        boolean deposit(int value) {
            balance += value;
            return true;
        }
        boolean withdraw(int value) {
            if (value > balance)
                return false;
            balance -= value;
            return true;
        }
    }

    private final Map<Integer, Account> map = new HashMap<>();
    private int nextId = 0;
    private final ReentrantLock lock = new ReentrantLock();  // Added lock
    private ReentrantReadWriteLock l = new ReentrantReadWriteLock();

    // create account and return account id
    public int createAccount(int balance) {
        Account c = new Account(balance);
        lock.lock();  // Locking to ensure thread-safe operation
        try {
            int id = nextId;
            nextId += 1;
            map.put(id, c);
            return id;
        } finally {
            lock.unlock();  // Ensuring the lock is released
        }
    }

    // close account and return balance, or 0 if no such account
    public int closeAccount(int id) {
        Account c;
        lock.lock();  // Locking for thread safety
        try {
            c = map.remove(id);
            if (c == null)
                return 0;
            ((ReentrantLock) c.lock).lock();
        } finally {
            lock.unlock();
        }
        try {
            return c.balance();
        } finally {
            ((ReentrantLock) c.lock).unlock();
        }
    }

    // account balance; 0 if no such account
    public int balance(int id) {
        lock.lock();  // Locking for thread safety
        try {
            Account c = map.get(id);
            if (c == null)
                return 0;
            return c.balance();
        } finally {
            lock.unlock();
        }
    }

    // deposit; fails if no such account
    public boolean deposit(int id, int value) {
        lock.lock();  // Locking for thread safety
        try {
            Account c = map.get(id);
            if (c == null)
                return false;
            return c.deposit(value);
        } finally {
            lock.unlock();
        }
    }

    // withdraw; fails if no such account or insufficient balance
    public boolean withdraw(int id, int value) {
        lock.lock();  // Locking for thread safety
        try {
            Account c = map.get(id);
            if (c == null)
                return false;
            return c.withdraw(value);
        } finally {
            lock.unlock();
        }
    }

    // transfer value between accounts;
    // fails if either account does not exist or insufficient balance
    public boolean transfer(int from, int to, int value) {
        Account cfrom = map.get(from);
        Account cto = map.get(to);
        l.readLock().lock();
        try {
            if (cfrom == null || cto == null)
                return false;
            if (from < to){
                ((ReentrantLock) cfrom.lock).lock();
                ((ReentrantLock) cto.lock).lock();
            } else {
                ((ReentrantLock) cto.lock).lock();
                ((ReentrantLock) cfrom.lock).lock();
            }
        } finally {
            l.readLock().unlock();
        }
        if (!cfrom.withdraw(value)) {
            ((ReentrantLock) cfrom.lock).unlock();
            ((ReentrantLock) cto.lock).unlock();
            return false;
        }
        ((ReentrantLock) cfrom.lock).unlock();
        boolean ok = cto.deposit(value);

        if (!ok) {
            ((ReentrantLock) cto.lock).unlock();
            return false;
        }
        ((ReentrantLock) cto.lock).unlock();
        return true;
    }

    // sum of balances in set of accounts; 0 if some does not exist
    public int totalBalanceV1(int[] ids) {
        lock.lock();  // Locking for thread safety
        try {
            int total = 0;
            List<ReentrantLock> acquiredLocks = new ArrayList<>();
            try {
            for (int id : ids) {
                Account c = map.get(id);
                if (c == null) {
                return 0;
                }
                ReentrantLock accountLock = (ReentrantLock) c.lock;
                accountLock.lock();
                acquiredLocks.add(accountLock);
            }
            for (int id : ids) {
                Account c = map.get(id);
                total += c.balance();
            }
            } finally {
            for (ReentrantLock accountLock : acquiredLocks) {
                accountLock.unlock();
            }
            }
            return total;
        } finally {
            lock.unlock();
        }
    }

    public int totalBalanceV2(int[] ids) {
        Account [] accounts = new Account[ids.length];
        lock.lock();  // Locking for thread safety
        try {
            for (int i = 0; i < ids.length; i++) {
                accounts [i] = map.get(ids[i]);
                if (accounts[i] == null) {
                    return 0;
                }
            }
        } finally {
            lock.unlock();
        }
        
        int total = 0;
        for (int i = 0; i < ids.length; i++) {
            ((ReentrantLock) accounts[i].lock).lock();
        }
        for (int i = 0; i < ids.length; i++) {
            total += accounts[i].balance();
        }
        for (int i = 0; i < ids.length; i++) {
            ((ReentrantLock) accounts[i].lock).unlock();
        }
        return total;
    }
}
