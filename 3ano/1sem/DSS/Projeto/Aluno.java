public class Aluno {
    private int numeroAluno;
    private String nome;

    // Construtores, getters e setters
    public Aluno(int numeroAluno, String nome) {
        this.numeroAluno = numeroAluno;
        this.nome = nome;
    }

    public Aluno () {
        this.numeroAluno = 0;
        this.nome = "";
    }

    public int getNumeroAluno() {
        return numeroAluno;
    }

    public String getNome() {
        return nome;
    }

    public void setNumeroAluno(int numeroAluno) {
        this.numeroAluno = numeroAluno;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public boolean temPrioridade() {
        return false;  // Alunos regulares não têm prioridade
    }

    public String toString() {
        return "Aluno: " + numeroAluno + ", " + nome;
    }

    public boolean equals(Aluno a) {
        return this.numeroAluno == a.getNumeroAluno() && this.nome.equals(a.getNome());
    }

    public Aluno clone() {
        return new Aluno(this.numeroAluno, this.nome);
    }
}
