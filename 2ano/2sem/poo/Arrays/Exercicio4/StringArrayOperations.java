import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class StringArrayOperations {
    private String[] array;

    public StringArrayOperations(String[] array) {
        this.array = array;
    }

    // (a) Determinar o array com as Strings sem repetições
    public String[] uniqueStrings() {
        return Arrays.stream(array).distinct().toArray(String[]::new);
    }

    // (b) Determinar a maior String inserida (lexicograficamente)
    public String largestString() {
        return Arrays.stream(array).max(String::compareTo).orElse(null);
    }

    // (c) Determinar um array com as Strings que aparecem mais de uma vez
    public String[] duplicateStrings() {
        Set<String> seen = new HashSet<>();
        Set<String> duplicates = new HashSet<>();
        for (String s : array) {
            if (!seen.add(s))
                duplicates.add(s);
        }
        return duplicates.toArray(new String[0]);
    }

    // (d) Determinar quantas vezes uma determinada String ocorre no array
    public long countOccurrences(String target) {
        return Arrays.stream(array).filter(s -> s.equals(target)).count();
    }
}
