public class TrabalhadorEstudante extends Aluno {
    public TrabalhadorEstudante(int numeroAluno, String nome) {
        super(numeroAluno, nome);
    }

    @Override
    public boolean temPrioridade() {
        return true;  // Trabalhadores-estudantes têm prioridade
    }
}
