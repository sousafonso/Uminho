package exe5;

// This class is used to calculate the total grade of a given UC
public class AlB {
    public static int notaUC(int[][] notas, int uc){
        int soma = 0;
        for (int i = 0; i < 5; i++) {
            soma += notas[i][uc];
        }
        return soma;
    }
}