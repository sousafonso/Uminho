import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Exercicios2 {
    private ArrayList<LocalDate> datas;

    public int ArrayMin (int [] a){
        int min = a[0];
        for (int i = 0; i < a.length; i++){
            if (a[i] < min) min = a[i];
        }
        return min;
    }

    public void insereData (LocalDate data){ 
        datas.add(data);
    }

    public LocalDate dataMaisProxima(LocalDate data) {
        LocalDate maisProxima = datas.get(0);
        for (LocalDate d : datas) {
            if (d.isAfter(data) && (maisProxima.isAfter(data) || d.isBefore(maisProxima))) {
                maisProxima = d;
            }
        }
        return maisProxima;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (LocalDate date : datas) {
            sb.append(date.toString()).append("\n");
        }
        return sb.toString();
    }

    /**
     * método que ordene um array de inteiros por ordem crescente;
     * @param array
     */
    public static void sortArray(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    // troca os elementos
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    /**
     * método que implemente a procura binária de um elemento num array de inteiros;
     * @param array
     * @param key
     * @return
     */
    public static int binarySearch(int[] array, int key) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (array[mid] == key) {
                return mid; // elemento encontrado
            }
            if (array[mid] < key) {
                left = mid + 1; // procura na metade direita
            } else {
                right = mid - 1; // procura na metade esquerda
            }
        }
        return -1; // elemento não encontrado
    }

    /**
     * determinar o array com as Strings existentes (sem repetições)
     * HashSet remove todos os elementos duplicados
     * @param array
     * @return
     */
    public static String[] uniqueStrings(String[] array) {
        Set<String> uniqueSet = new HashSet<>();
        for (String str : array) {
            uniqueSet.add(str); // adiciona cada string ao conjunto
        }
        return uniqueSet.toArray(new String[0]); // converte o Set de volta para um array
    }

    /**
     * determinar a maior String inserida;
     * @param array
     * @return
     */
    public static String longestString(String[] array) {
        String longest = ""; // inicialização da variavel
        for (String str : array) {
            if (str.length() > longest.length()) {
                longest = str;
            }
        }
        return longest;
    }

    /**
     * determinar um array com as Strings que aparecem mais de uma vez;
     * @param array
     * @return
     */
    public static String[] duplicateStrings(String[] array) {
        Set<String> duplicates = new HashSet<>();
        Set<String> seen = new HashSet<>();

        for (String str : array) {
            if (!seen.add(str)) { // se o elemento já foi visto, adiciona ao conjunto de duplicados
                duplicates.add(str);
            }
        }
        return duplicates.toArray(new String[0]); // converte o Set de volta para um array
    }

    /**
     * determinar quantas vezes uma determinada String ocorre no array.
     * @param array
     * @param target
     * @return
     */
    public static int countOccurrences(String[] array, String target) {
        int count = 0;
        for (String str : array) {
            if (str.equals(target)) { // acho que quando temos strings temos de usar .equals
                count++;
            }
        }
        return count;
    }
}