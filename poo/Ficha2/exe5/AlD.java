package exe5;

// Calcula a média de uma UC
public class AlD {
    public static float muc (int [][] notas, int uc){
        int soma = 0;
        for (int i = 0; i < 5; i++){
            soma += notas[i][uc];
        }
        return soma/5;
    }
}
