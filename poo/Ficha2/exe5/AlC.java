package exe5;

// This class is used to calculate the average of a student's grades
public class AlC {
    public static float mediaAluno (int[] notas){
        float soma = 0;
        for (int i = 0; i < notas.length; i++) {
            soma += notas[i];
        }
        return soma / notas.length;
    }
}
