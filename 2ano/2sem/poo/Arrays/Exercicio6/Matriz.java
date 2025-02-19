import java.util.Scanner;

public class Matriz {
    public static int[][] lerMatriz(int linhas, int colunas) {
        Scanner sc = new Scanner(System.in);
        int[][] matriz = new int[linhas][colunas];
        System.out.println("Digite os elementos da matriz:");
        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
                matriz[i][j] = sc.nextInt();
        return matriz;
    }

    public static int[][] somaMatrizes(int[][] m1, int[][] m2) {
        int l = m1.length, c = m1[0].length;
        int[][] resultado = new int[l][c];
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
                resultado[i][j] = m1[i][j] + m2[i][j];
        return resultado;
    }

    public static boolean matrizesIguais(int[][] m1, int[][] m2) {
        if(m1.length != m2.length || m1[0].length != m2[0].length)
            return false;
        for (int i = 0; i < m1.length; i++)
            for (int j = 0; j < m1[0].length; j++)
                if(m1[i][j] != m2[i][j])
                    return false;
        return true;
    }

    public static int[][] matrizOposta(int[][] matriz) {
        int l = matriz.length, c = matriz[0].length;
        int[][] oposta = new int[l][c];
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
                oposta[i][j] = -matriz[i][j];
        return oposta;
    }
}
