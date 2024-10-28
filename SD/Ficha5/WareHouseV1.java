/**
 * @author: Afonso Sousa
 * @escription: Implementação de um armazém com métodos de fornecimento e consumo de produtos
 *  versão “egoísta”, centrada nos clientes, em que cada cliente tenta apropriar-se dos itens o
 *  mais cedo possível
 * @Date: 18/10/2024
 * @version 1
 * @exercise 1
 */

import java.util.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.*;

class WarehouseV1 {
    private Map<String, Product> map =  new HashMap<String, Product>();
    private Lock l = new ReentrantLock();
    private Condition c = l.newCondition();

    private class Product { 
        int quantity = 0; 
        Condition c = l.newCondition();
    }

    /**
     * Método auxiliar para obter um produto
     * @param item
     * @return
     */
    private Product get(String item) {
        Product p = map.get(item);
        if (p != null) return p;
        p = new Product();
        map.put(item, p);
        return p;
    }

    /**
     * Método para adicionar um produto ao armazém
     * @param item
     * @param quantity
     */
    public void supply(String item, int quantity) throws InterruptedException {
        l.lock();
        try {
            Product p = get(item);
            p.quantity += quantity;
            p.c.signalAll();
        } finally {
            l.unlock();
        }
    }

    /**
     * Método para consumir um conjunto de produtos
     * @param items
     */
    public void consume(Set<String> items) throws InterruptedException {
        l.lock();
        try {
            for (String s : items) {
                Product p = get(s);
                while (p.quantity == 0) p.c.await();
                p.quantity--;
            }
        } finally {
            l.unlock();
        }
    }

}