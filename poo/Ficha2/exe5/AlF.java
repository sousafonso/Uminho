package exe5;

public class AlF {
    public static void sup (int [][] notas, double li){
        double [] newarray = {0};

        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (notas[i][j] > li){
                    newarray[i] = notas[i][j];
                }
            }
        }

        System.out.println("Os valores acima desse limite são:");
        for (int i = 0; i < newarray.length; i++){
            System.out.println(newarray[i]);
        }
    }
}
