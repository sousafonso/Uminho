import java.util.Scanner;

public class Maximo {
    public static void main(String[] args) {
        System.out.println("Introduza dois números inteiros:");
        Scanner sc = new Scanner(System.in);

        scanner.close();
        int a = sc.nextInt();
        int b = sc.nextInt();

        if (a > b) {
            System.out.println("O valor máximo é: " + a);
        } else {
            System.out.println("O valor máximo é: " + b);
        }
    }
}