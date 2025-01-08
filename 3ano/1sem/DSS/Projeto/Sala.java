public class Sala {
    private String codigo;
    private int capacidade;
    private String tipo;  // Ex: Teórica, TP, PL

    // Construtores, getters e setters
    public Sala(String codigo, int capacidade, String tipo) {
        this.codigo = codigo;
        this.capacidade = capacidade;
        this.tipo = tipo;
    }

    public Sala() {
        this.codigo = "";
        this.capacidade = 0;
        this.tipo = "";
    }

    public String getCodigo() {
        return codigo;
    }

    public int getCapacidade() {
        return capacidade;
    }

    public String getTipo() {
        return tipo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public void setCapacidade(int capacidade) {
        this.capacidade = capacidade;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String toString() {
        return "Sala: " + codigo + ", " + capacidade + ", " + tipo;
    }

    public boolean equals(Sala s) {
        return this.codigo.equals(s.getCodigo()) && this.capacidade == s.getCapacidade() && this.tipo.equals(s.getTipo());
    }

    public Sala clone() {
        return new Sala(this.codigo, this.capacidade, this.tipo);
    }
}
