import java.util.ArrayList;

public class GradeSheet{
    private int [][] grades = new int[5][5];

    public GradeSheet(int students, int subjects) {
        grades = new int[students][subjects];
    }

    public void readGrades(int studentIndex, int[] studentGrades) {
        grades[studentIndex] = studentGrades;
    }

    public int somaGrades (int uc, int[][] studentGrades){
        int soma = 0;
        for (int i = 0; i < 5; i++){
            soma += studentGrades[i][uc];
        }
        return soma;
    }

    public double mediaAluno (int aluno, int [][] studentGrades){
        double media = 0;
        for (int i = 0; i < 5; i++) media += studentGrades[aluno][i];
        return media;
    }

    public double mediaUC (int uc, int [][] studentGrades){
        double media = 0;
        for (int i = 0; i < 5; i++) media += studentGrades[i][uc];
        return media;
    }

    public double mediaUCV2(int subjectIndex) {
        double total = 0;
        for (int[] studentGrades : grades) {
            total += studentGrades[subjectIndex];
        }
        return total / grades.length;
    }

    public int maisAlta (int [][] studentGrades){
        int nota = 0;
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (nota < studentGrades[i][j]) nota = studentGrades[i][j];
            }
        }
        return nota;
    }

    public int maisAltaV2() {
        int highest = Integer.MIN_VALUE;
        for (int[] studentGrades : grades) {
            for (int grade : studentGrades) {
                if (grade > highest) {
                    highest = grade;
                }
            }
        }
        return highest;
    }

    public int maisBaixa (int [][] studentGrades){
        int nota = Integer.MAX_VALUE;
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (nota > studentGrades[i][j]) nota = studentGrades[i][j];
            }
        }
        return nota;
    }

    public int maisBaixaV2() {
        int lowest = Integer.MAX_VALUE;
        for (int[] studentGrades : grades) {
            for (int grade : studentGrades) {
                if (grade < lowest) {
                    lowest = grade;
                }
            }
        }
        return lowest;
    }

    public int [] notasAltas (int [][] studentGrades, int valor){
        int [] notasAltas = new int[25];
        int index = 0;
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if (studentGrades[i][j] > valor){
                    notasAltas[index] = studentGrades[i][j];
                    index++;
                }
            }
        }
        return notasAltas;
    }

    public int[] notasAltasV2 (int value) {
        ArrayList<Integer> aboveValue = new ArrayList<>();
        for (int[] studentGrades : grades) {
            for (int grade : studentGrades) {
                if (grade > value) {
                    aboveValue.add(grade);
                }
            }
        }
        return aboveValue.stream().mapToInt(i -> i).toArray();
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int[] studentGrades : grades) {
            for (int grade : studentGrades) {
                sb.append(grade).append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }

    public int maiorMedia (int [][] studentGrades){
        double maiorMedia = 0;
        int aluno = 0;
        for (int i = 0; i < 5; i++){
            double media = mediaAluno(i, studentGrades);
            if (maiorMedia < media){
                maiorMedia = media;
                aluno = i;
            }
        }
        return aluno;
    }
}

/**
 * ArrayList, array dinamico
 * Array normal não é dinamico
 */