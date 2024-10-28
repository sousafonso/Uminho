/**
 * @author Afonso Sousa
 * @Description: A segunda versão do armazém poderá levar a situações de starvation, em que um dado cliente
    continua à espera indefinidamente, quando os itens desejados, e que foram entretanto chegando,
    vão sendo atribuídos a outros clientes. Modifique o armazém para, mantendo-se cooperativo,
    evitar este problema.
 * @Date: 18/10/2024
 * @version 3
 * @exercise 2
 */

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;

public class WareHouseV3 {
    private Map<String, Product> map = new HashMap<String, Product>();
    private Lock l;
    private Condition c;

    private class Product {
        int quantity = 0;
        Queue<Condition> q = new LinkedList<>();
    }

    private Product get(String item) {
        Product p = map.get(item);
        if (p != null) return p;
        p = new Product();
        map.put(item, p);
        return p;
    }

    public WareHouseV3(Lock l) {
        this.l = l;
        this.c = l.newCondition();
    }

    public void supply(String item, int quantity) throws InterruptedException {
        l.lock();
        try {
            Product p = get(item);
            p.quantity += quantity;
            while (!p.q.isEmpty()) {
                p.q.poll().signal();
            }
        } finally {
            l.unlock();
        }
    }

    private Product missing (Product [] p) {
        for (Product product : p) {
            if () return product;
        }
        return null;
    }

    public void consume(Set<String> items) throws InterruptedException {
        l.lock();
        try {
            Product [] p = new Product[items.size()];
            int i = 0;
            for (String s : items) {
                p[i++] = get(s);
            }
            Product missing = missing(p);
            while (missing != null) {
                Condition c = l.newCondition();
                missing.q.add(c);
                c.await();
                missing = missing(p);
            }
            for (Product product : p) {
                product.quantity--;
            }
        } finally {
            l.unlock();
        }
    }
}
