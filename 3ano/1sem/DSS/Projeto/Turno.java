public class Turno{

    private String codigo;
    private int vagas;
    private boolean prioridadeAlocacao;  // Indica se é priorizado para status especial
    private Sala sala;
    private Horario horario;

    public boolean alocarAluno(Turno turno, Aluno aluno) {
        if (turno.getVagas() > 0 && aluno.temPrioridade()) {
            turno.setVagas(turno.getVagas() - 1);
            return true;  // Alocação bem-sucedida
        }
        return false;  // Falha na alocação
    }

    public boolean verificarDisponibilidade(Turno turno) {
        return turno.getVagas() > 0;
    }

    public Turno(String codigo, int vagas, boolean prioridadeAlocacao, Sala sala, Horario horario) {
        this.codigo = codigo;
        this.vagas = vagas;
        this.prioridadeAlocacao = prioridadeAlocacao;
        this.sala = sala;
        this.horario = horario;
    }

    public Turno() {
        this.codigo = "";
        this.vagas = 0;
        this.prioridadeAlocacao = false;
        this.sala = new Sala();
        this.horario = new Horario();
    }

    public String getCodigo() {
        return codigo;
    }

    public int getVagas() {
        return vagas;
    }

    public boolean getPrioridadeAlocacao() {
        return prioridadeAlocacao;
    }

    public Sala getSala() {
        return sala;
    }

    public Horario getHorario() {
        return horario;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public void setVagas(int vagas) {
        this.vagas = vagas;
    }

    public void setPrioridadeAlocacao(boolean prioridadeAlocacao) {
        this.prioridadeAlocacao = prioridadeAlocacao;
    }

    public void setSala(Sala sala) {
        this.sala = sala;
    }

    public void setHorario(Horario horario) {
        this.horario = horario;
    }

    public String toString() {
        return "Turno: " + codigo + ", " + vagas + ", " + prioridadeAlocacao + ", " + sala + ", " + horario;
    }

    public boolean equals(Turno t) {
        return this.codigo.equals(t.getCodigo()) && this.vagas == t.getVagas() && this.prioridadeAlocacao == t.getPrioridadeAlocacao() && this.sala.equals(t.getSala()) && this.horario.equals(t.getHorario());
    }

    public Turno clone() {
        return new Turno(this.codigo, this.vagas, this.prioridadeAlocacao, this.sala.clone(), this.horario.clone());
    }
}