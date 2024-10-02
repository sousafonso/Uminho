// Subclasse Atleta
public class Atleta extends Aluno {
    public Atleta(int numeroAluno, String nome) {
        super(numeroAluno, nome);
    }

    @Override
    public boolean temPrioridade() {
        return true;  // Atletas têm prioridade
    }
}
