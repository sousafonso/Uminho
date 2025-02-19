import java.util.Scanner;
import java.util.Arrays;

public class TesteStringArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Quantas Strings? ");
        int n = sc.nextInt();
        sc.nextLine(); // consumir nova linha
        String[] arr = new String[n];
        System.out.println("Digite as Strings:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLine();
        }
        
        StringArrayOperations sao = new StringArrayOperations(arr);
        System.out.println("Strings únicas: " + Arrays.toString(sao.uniqueStrings()));
        System.out.println("Maior String: " + sao.largestString());
        System.out.println("Strings duplicadas: " + Arrays.toString(sao.duplicateStrings()));
        System.out.print("Informe uma String para contar ocorrências: ");
        String target = sc.nextLine();
        System.out.println("Ocorrências: " + sao.countOccurrences(target));
    }
}
