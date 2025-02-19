import java.util.Scanner;

public class TestePauta {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Pauta pauta = new Pauta();
        int[][] notas = new int[5][5];

        System.out.println("Digite as notas (5 alunos x 5 UCs):");
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                notas[i][j] = sc.nextInt();
        
        pauta.atualizarNotas(notas);
        System.out.println("Soma UC 0: " + pauta.somaNotasUnidadeCurricular(0));
        System.out.println("Média aluno 0: " + pauta.mediaNotasAluno(0));
        System.out.println("Média UC 0: " + pauta.mediaNotasUnidadeCurricular(0));
        System.out.println("Nota mais alta: " + pauta.notaMaisAlta());
        System.out.println("Nota mais baixa: " + pauta.notaMaisBaixa());
        
        int[][] acima = pauta.notasAcimaDe(10);
        System.out.println("Notas acima de 10:");
        for (int[] aluno : acima) {
            for (int nota : aluno)
                System.out.print(nota + " ");
            System.out.println();
        }
        System.out.println("Todas as notas:\n" + pauta.todasAsNotas());
        System.out.println("UC com média mais elevada: " + pauta.unidadeCurricularComMediaMaisElevada());
    }
}
