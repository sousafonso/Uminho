import java.util.HashSet;
import java.util.Set;
import java.util.Arrays;

public class ArrayOperations {

    // (a) Método que retorna o valor mínimo do array
    public static int findMinimum(int[] array) {
        int min = array[0];
        for (int num : array) {
            if(num < min) {
                min = num;
            }
        }
        return min;
    }
    
    // (b) Método que retorna os elementos entre start e end (inclusive)
    public static int[] subArray(int[] array, int start, int end) {
        int[] result = new int[end - start + 1];
        for (int i = start, j = 0; i <= end; i++, j++) {
            result[j] = array[i];
        }
        return result;
    }

    public static int[] subArray2 (int[] array, int start, int end) {
        return Arrays.copyOfRange(array, start, end + 1);
    }
    
    // (c) Método que retorna um array com os elementos comuns entre os dois arrays
    public static int[] commonElements(int[] array1, int[] array2) {
        Set<Integer> set1 = new HashSet<>();
        for (int n : array1)
            set1.add(n);
        Set<Integer> commons = new HashSet<>();
        for (int n : array2)
            if(set1.contains(n))
                commons.add(n);
        int[] result = new int[commons.size()];
        int i = 0;
        for (int n : commons)
            result[i++] = n;
        return result;
    }
}
