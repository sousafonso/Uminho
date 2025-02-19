public class TesteMatriz {
    public static void main(String[] args) {
        int[][] m1 = Matriz.lerMatriz(2, 2);
        int[][] m2 = Matriz.lerMatriz(2, 2);
        
        int[][] soma = Matriz.somaMatrizes(m1, m2);
        System.out.println("Soma:");
        for (int[] linha : soma) {
            for (int x : linha)
                System.out.print(x + " ");
            System.out.println();
        }
        
        System.out.println("Matrizes iguais? " + Matriz.matrizesIguais(m1, m2));
        
        int[][] oposta = Matriz.matrizOposta(m1);
        System.out.println("Matriz oposta:");
        for (int[] linha : oposta) {
            for (int x : linha)
                System.out.print(x + " ");
            System.out.println();
        }
    }
}
