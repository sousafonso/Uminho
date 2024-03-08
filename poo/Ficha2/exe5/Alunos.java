package exe5;
import java.util.Random;
import java.util.Scanner;

public class Alunos {
    public static void main(String[] args) {
        int[][] notas = new int[5][5];
        Random random = new Random();

        // preencher a tabela com valores aleatórios
        for (int i = 0; i < notas.length; i++) {
            for (int j = 0; j < notas[i].length; j++) {
                notas[i][j] = random.nextInt(21); 
            }
        }

        System.out.println("Escolha uma UC para calcular o total das notas (1,2,3,4 ou 5):");
        Scanner scanner = new Scanner(System.in);
        int uc = scanner.nextInt();

        System.out.println("A nota total da UC " + uc + " é: " + AlB.notaUC(notas, uc-1));
        
        System.out.println("Escolha um aluno para calcular a média das suas notas (1,2,3,4 ou 5):");

        int aluno = scanner.nextInt();

        System.out.println("A média do aluno " + aluno + " é: " + AlC.mediaAluno(notas[aluno-1]));

        System.out.println("Selecione uma UC para calcular a média na mesma (1,2,3,4 e 5): ");

        float muc = scanner.nextInt();

        System.out.println("A média da UC foi de" + AlD.muc(notas, uc));

        System.out.println("A nota mais alta foi de" + AlE.mmuc(notas));

        System.out.println("Introduza um limite inferior para saber as notas acima desse mesmo limite (de 0 a 20)");
        double li = scanner.nextDouble();

        AlF.sup(notas, li);

        System.out.println("A UC com maior média é:" + AlI.mmedia(notas));
        
        scanner.close();
    }

}
