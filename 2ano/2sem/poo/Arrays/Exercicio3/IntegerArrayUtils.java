import java.util.Arrays;

public class IntegerArrayUtils {

    // (a) Ordena um array de inteiros por ordem crescente
    public static void sortArray(int[] array) {
        Arrays.sort(array);
    }

    // (b) Implementa a procura binária de um elemento no array
    public static int binarySearch(int[] array, int key) {
        return Arrays.binarySearch(array, key);
    }
}
