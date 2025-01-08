package Aula4;

public class Lugar {
    private String informacao;
    private String matricula;
    private int tempo;
    private boolean permanente;

    public Lugar(String informacao, String matricula, int tempo, boolean permanente) {
        this.informacao = informacao;
        this.matricula = matricula;
        this.tempo = tempo;
        this.permanente = permanente;
    }

    public String getInformacao() {
        return this.informacao;
    }

    public String getMatricula() {
        return this.matricula;
    }

    public int getTempo() {
        return this.tempo;
    }

    public boolean getPermanente() {
        return this.permanente;
    }

    public boolean isPermanente() {
        return permanente;
    }

    public void setInformacao(String informacao) {
        this.informacao = informacao;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public void setTempo(int tempo) {
        this.tempo = tempo;
    }

    public void setPermanente(boolean permanente) {
        this.permanente = permanente;
    }

    public Lugar clone() {
        return new Lugar(this.informacao, this.matricula, this.tempo, this.permanente);
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || this.getClass() != o.getClass()) {
            return false;
        }
        Lugar l = (Lugar) o;
        return this.informacao.equals(l.getInformacao()) && this.matricula.equals(l.getMatricula())
                && this.tempo == l.getTempo() && this.permanente == l.getPermanente();
    }
}
