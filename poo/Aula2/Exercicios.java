import java.time.LocalDate;
import java.util.ArrayList;

public class Exercicios2 {
    private ArrayList<LocalDate> datas;

    public int ArrayMin (int [] a){
        int min = a[0];
        for (int i = 0; i < a.length; i++){
            if (a[i] < min) min = a[i];
        }
        return min;
    }

    public void insereData (LocalDate data) datas.add(data);

    public LocalDate dataMaisProxima(LocalDate data) {
        LocalDate closestDate = null;
        long minDifference = Long.MAX_VALUE;

        for (LocalDate date : dates) {
            long difference = Math.abs(date.toEpochDay() - data.toEpochDay());
            if (difference < minDifference) {
                minDifference = difference;
                closestDate = date;
            }
        }

        return closestDate;
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
        Arrays.sort(array);
    }

    /**
     * método que implemente a procura binária de um elemento num array de inteiros;
     * @param array
     * @param key
     * @return
     */
    public static int binarySearch(int[] array, int key) {
        return Arrays.binarySearch(array, key);
    }

    /**
     * determinar o array com as Strings existentes (sem repetições)
     * HashSet remove todos os elementos duplicados
     * @param array
     * @return
     */
    public static String[] uniqueStrings(String[] array) {
        Set<String> uniqueSet = new HashSet<>(Arrays.asList(array)); // convertemos o array numa lista e depois transformamos num HashSet para eliminar os duplicados
        return uniqueSet.toArray(new String[0]); // voltamos a converter para array
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
        Map<String, Integer> countMap = new HashMap<>();
        for (String str : array) {
            countMap.put(str, countMap.getOrDefault(str, 0) + 1);
        }

        List<String> duplicates = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : countMap.entrySet()) {
            if (entry.getValue() > 1) {
                duplicates.add(entry.getKey());
            }
        }

        return duplicates.toArray(new String[0]);
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