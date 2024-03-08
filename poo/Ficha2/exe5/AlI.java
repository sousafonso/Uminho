package exe5;

public class AlI {
    public static float mmedia (int [][] notas){
        float media = 0;
        for(int i = 0; i < 5; i++){
            for (int j = 0; j<5; j++){
                if (media < AlD.muc(notas, j)){
                    media = AlD.muc(notas, j);
                }
            }
        }
        return media;
    }
}
