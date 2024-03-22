public class Aluno {
    private String nome;
    private int numero;
    private int idade;
    private String curso;
    private int ano;
    private int[] notas;
    private int nNotas;
    private static final int MAX_NOTAS = 100;

    public Aluno() {
        nome = "";
        numero = 0;
        idade = 0;
        curso = "";
        ano = 0;
        notas = new int[MAX_NOTAS];
        nNotas = 0;
    }

    public Aluno(String nome, int numero, int idade, String curso, int ano, int[] notas, int nNotas) {
        this.nome = nome;
        this.numero = numero;
        this.idade = idade;
        this.curso = curso;
        this.ano = ano;
        this.notas = notas;
        this.nNotas = nNotas;
    }

    public Aluno(Aluno aluno) {
        nome = aluno.getNome();
        numero = aluno.getNumero();
        idade = aluno.getIdade();
        curso = aluno.getCurso();
        ano = aluno.getAno();
        notas = aluno.getNotas();
        nNotas = aluno.getNNotas();
    }

    public String getNome() {
        return nome;
    }

    public int getNumero() {
        return numero;
    }

    public int getIdade() {
        return idade;
    }

    public String getCurso() {
        return curso;
    }

    public int getAno() {
        return ano;
    }

    public int[] getNotas() {
        return notas;
    }

    public int getNNotas() {
        return nNotas;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public void setNotas(int[] notas) {
        this.notas = notas;
    }

    public void setNNotas(int nNotas) {
        this.nNotas = nNotas;
    }

    public double mediaNotas() {
        double media = 0;
        for (int i = 0; i < nNotas; i++) {
            media += notas[i];
        }
        return media / nNotas;
    }

    public Aluno clone() {
        return new Aluno(this);
    }
}