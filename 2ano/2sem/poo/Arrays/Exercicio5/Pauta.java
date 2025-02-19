public class Pauta {
    private int[][] notasTurma = new int[5][5];

    public void atualizarNotas(int[][] notas) {
        this.notasTurma = notas;
    }

    public int somaNotasUnidadeCurricular(int ucIndex) {
        int soma = 0;
        for (int i = 0; i < 5; i++)
            soma += notasTurma[i][ucIndex];
        return soma;
    }

    public double mediaNotasAluno(int alunoIndex) {
        int soma = 0;
        for (int j = 0; j < 5; j++)
            soma += notasTurma[alunoIndex][j];
        return soma / 5.0;
    }

    public double mediaNotasUnidadeCurricular(int ucIndex) {
        return somaNotasUnidadeCurricular(ucIndex) / 5.0;
    }

    public int notaMaisAlta() {
        int max = Integer.MIN_VALUE;
        for (int[] aluno : notasTurma)
            for (int nota : aluno)
                if(nota > max)
                    max = nota;
        return max;
    }

    public int notaMaisBaixa() {
        int min = Integer.MAX_VALUE;
        for (int[] aluno : notasTurma)
            for (int nota : aluno)
                if(nota < min)
                    min = nota;
        return min;
    }

    public int[][] notasAcimaDe(int valor) {
        int[][] result = new int[5][5];
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                result[i][j] = (notasTurma[i][j] > valor) ? notasTurma[i][j] : 0;
        return result;
    }

    public String todasAsNotas() {
        StringBuilder sb = new StringBuilder();
        for (int[] aluno : notasTurma) {
            for (int nota : aluno)
                sb.append(nota).append(" ");
            sb.append("\n");
        }
        return sb.toString();
    }

    public int unidadeCurricularComMediaMaisElevada() {
        int ucIndex = -1;
        double maxMedia = Double.MIN_VALUE;
        for (int i = 0; i < 5; i++) {
            double media = mediaNotasUnidadeCurricular(i);
            if(media > maxMedia) {
                maxMedia = media;
                ucIndex = i;
            }
        }
        return ucIndex;
    }
}
