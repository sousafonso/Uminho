/**
 * @author: Afonso Sousa
 * @Description: Implementação de um armazém com métodos de fornecimento e consumo de produtos.
 *  versão “cooperativa”, que optimiza o uso do armazém como um todo, não reservando
 *  itens para clientes que não possam ser satisfeitos no momento (porque faltam alguns)
 * @Date: 18/10/2024
 * @version 2
 * @exercise 1
 */

 import java.util.*;
 import java.util.concurrent.locks.Condition;
 import java.util.concurrent.locks.*;
 
 class WarehouseV2 {
     private Map<String, Product> map =  new HashMap<String, Product>();
     Lock l = new ReentrantLock();
     private Condition c = l.newCondition();
 
     /**
      * Classe interna para representar um produto e como não é static, tem acesso ao lock e à condição do armazém
      * estão implicitamente associados ao armazém
      */
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
                boolean flag = false; // flag para verificar se TODOS os produtos estão disponíveis
                while (!flag) {
                    flag = true;
                    for (String item : items) {
                        Product p = get(item);
                        if (p.quantity == 0) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) c.await();
                }
                for (String item : items) {
                    Product p = get(item);
                    p.quantity--;
                }
            } finally {
                l.unlock();
            }
     }
 
 }