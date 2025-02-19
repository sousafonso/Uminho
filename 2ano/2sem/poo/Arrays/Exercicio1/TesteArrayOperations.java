import java.util.Scanner;
import java.util.Arrays;

public class TesteArrayOperations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Ler um array de inteiros para testar o mínimo
        System.out.print("Quantos elementos no array? ");
        int n = sc.nextInt();
        int[] array = new int[n];
        System.out.println("Digite os inteiros:");
        for (int i=0; i<n; i++) {
            array[i] = sc.nextInt();
        }
        System.out.println("Mínimo: " + ArrayOperations.findMinimum(array));

        // Ler dois índices para extrair subarray
        System.out.print("Digite índice inicial e final: ");
        int start = sc.nextInt();
        int end = sc.nextInt();
        int[] sub = ArrayOperations.subArray(array, start, end);
        System.out.println("Subarray: " + Arrays.toString(sub));

        // Ler dois arrays para obter elementos comuns
        System.out.print("Quantidade elementos do 1º array: ");
        int m = sc.nextInt();
        int[] array1 = new int[m];
        System.out.println("Digite os elementos do 1º array:");
        for (int i=0; i<m; i++) {
            array1[i] = sc.nextInt();
        }
        System.out.print("Quantidade elementos do 2º array: ");
        int k = sc.nextInt();
        int[] array2 = new int[k];
        System.out.println("Digite os elementos do 2º array:");
        for (int i=0; i<k; i++) {
            array2[i] = sc.nextInt();
        }
        int[] comuns = ArrayOperations.commonElements(array1, array2);
        System.out.println("Elementos comuns: " + Arrays.toString(comuns));
    }
}
