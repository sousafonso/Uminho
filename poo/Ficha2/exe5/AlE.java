package exe5;

public class AlE {
    public static float mmuc (int [][] notas){
        int max = notas[0][0];
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (max < notas [i][j]){
                    max = notas [i][j];
                }
            }
        }
        return max;
    }
}