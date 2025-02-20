import java.util.Scanner;
import java.util.Arrays;

public class TesteIntegerArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Quantos elementos? ");
        int n = sc.nextInt();
        int[] array = new int[n];
        System.out.println("Digite os inteiros:");
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        
        // Ordenar o array
        IntegerArrayUtils.sortArray(array);
        System.out.println("Array ordenado: " + Arrays.toString(array));
        
        // Procura binária
        System.out.print("Informe o valor para busca: ");
        int key = sc.nextInt();
        int index = IntegerArrayUtils.binarySearch(array, key);
        System.out.println("Índice do valor (" + key + "): " + index);
    }
}
