package Aula3;

import java.util.ArrayList;
import java.util.List;

public class Stack {
    private List<String> stack;

    public Stack() {
        this.elementos = new ArrayList<>();
    }

    public String top(){
        if (!stack.isEmpty()) return stack.get(stack.size()-1);
        else return null;
    }

    public void push(String s){
        stack.add(s);
    }

    public void pop(){
        if(!stack.isEmpty()) stack.remove(0);
    }

    public boolean empty(){
        return stack.isEmpty();
    }

    public int length (){
        return stack.size();
    }

    public static void main(String[] args) {
        Stack pilha = new Stack();

        // Testando a pilha
        System.out.println("A pilha está vazia? " + pilha.empty());

        pilha.push("Primeiro");
        pilha.push("Segundo");
        pilha.push("Terceiro");

        System.out.println("Elemento no topo: " + pilha.top());
        System.out.println("Comprimento da pilha: " + pilha.length());

        pilha.pop();
        System.out.println("Elemento no topo após pop: " + pilha.top());
        System.out.println("Comprimento da pilha após pop: " + pilha.length());

        pilha.pop();
        pilha.pop();
        pilha.pop(); // Tentativa de remover de uma pilha vazia

        System.out.println("A pilha está vazia após todas as operações? " + pilha.empty());

        // Testando a iteração sobre a pilha
        pilha.push("Novo Primeiro");
        pilha.push("Novo Segundo");

        System.out.println("Iterando sobre a pilha:");
        for (String elemento : pilha) {
            System.out.println(elemento);
        }
    }
}
