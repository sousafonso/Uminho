public class Exec1alinA {
    public int min (int[] valores) {
        int min = Integer.MAX_VALUE;
        for (int v : valores) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }
}