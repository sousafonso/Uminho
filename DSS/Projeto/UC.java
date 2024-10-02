public class UC {
    private String codigo;
    private String nome;
    private int ects;

    // Construtores, getters e setters
    public UC(String codigo, String nome, int ects) {
        this.codigo = codigo;
        this.nome = nome;
        this.ects = ects;
    }

    public UC() {
        this.codigo = "";
        this.nome = "";
        this.ects = 0;
    }

    public String getCodigo() {
        return codigo;
    }

    public String getNome() {
        return nome;
    }

    public int getEcts() {
        return ects;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setEcts(int ects) {
        this.ects = ects;
    }

    public String toString() {
        return "UC: " + codigo + ", " + nome + ", " + ects;
    }

    public boolean equals(UC uc) {
        return this.codigo.equals(uc.getCodigo()) && this.nome.equals(uc.getNome()) && this.ects == uc.getEcts();
    }

    public UC clone() {
        return new UC(this.codigo, this.nome, this.ects);
    }
}