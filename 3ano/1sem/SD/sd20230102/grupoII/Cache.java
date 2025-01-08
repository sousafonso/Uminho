package grupoII;

import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

interface Cache {
    void put(int key, byte[] value) throws InterruptedException; // Insere um valor em cache associado à chave key
    byte[] get(int key);
    void evict(int key); // Remove o valor associado à chave key
}

class CacheImpl implements Cache {
    private final Map<Integer, byte[]> cache = new ConcurrentHashMap<>(); // Mapa de chaves para valores em cache (byte[])
    private final Set<Integer> keys = new LinkedHashSet<>(); // Conjunto de chaves em cache
    private final ReentrantLock lock = new ReentrantLock();
    private final Condition notFull = lock.newCondition();
    private final int N; // Número máximo de chaves em cache
    private final int size = 0; // numero de entradas verdadeiras na cache

    private class Entry {
        byte[] value;
        Condition notUsed = lock.newCondition();
    }

    public CacheImpl (int N) {
        this.N = N;
    }

    public void put(int key, byte[] value) throws InterruptedException {
        lock.lock();
        try {
            while (keys.size() == N) {
                notFull.await();
            }
            keys.add(key);
            cache.put(key, value);
        } finally {
            lock.unlock();
        }
    }

    public byte[] get(int key) {
        lock.lock();
        try {
            return cache.get(key);
        } finally {
            lock.unlock();
        }
    }

    public void evict(int key) {
        lock.lock();
        try {
            keys.remove(key);
            cache.remove(key);
            notFull.signal();
        } finally {
            lock.unlock();
        }
    }
}