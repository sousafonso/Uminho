import java.util.Arrays;
import java.util.Scanner;

public class E1Teste {
    public static void main(String[] args) {
      Scanner s = new Scanner(System.in);
      int n;
        System.out.println("Quantos valores quer ler? ");
        n = s.nextInt();

        int [] valores = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Introduza o valor " + (i+1) + ": ");
            valores[i] = s.nextInt();
        }

        Exec1alinA e = new Exec1alinA();
        System.out.println("O mínimo do array é: " + e.min(valores));

        System.out.println("Introduza o limite inferior: ");
        int min = s.nextInt();
        System.out.println("Introduza o limite superior: ");
        int max = s.nextInt();

        Exec1alinB e1 = new Exec1alinB();
        System.out.println("O numero de valores entre " + min + " e " + max + " é: " + Arrays.toString(e1.entre(valores, min, max)));

    }
}