public class Stack {
    private int[] stack;
    private int top;
    private int size;

    public Stack(int size) {
        this.size = size;
        stack = new int[size];
        top = -1;
    }

    public String top () {
        if (top == -1) {
            return "Stack is empty";
        } else {
            return "Top: " + stack[top];
        }
    }

    public void push(String s) {
        if (top == size - 1) {
            System.out.println("Stack is full");
        } else {
            stack[++top] = Integer.parseInt(s);
        }
    }

    public void pop() {
        if (top == -1) {
            System.out.println("Stack is empty");
        } else {
            top--;
        }
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == size - 1;
    }

    public int length() {
        return top + 1;
    }

    public void print() {
        for (int i = 0; i <= top; i++) {
            System.out.print(stack[i] + " ");
        }
        System.out.println();
    }
}