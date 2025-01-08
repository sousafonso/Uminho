import java.time.LocalDateTime;
import java.time.LocalTime;

public class Horario{
    private String horaInicio;
    private String horaFim;
    private String diaSemana;

    public Horario(String horaInicio, String horaFim, String diaSemana) {
        this.horaInicio = horaInicio;
        this.horaFim = horaFim;
        this.diaSemana = diaSemana;
    }

    public Horario() {
        this.horaInicio = "";
        this.horaFim = "";
        this.diaSemana = "";
    }

    public String getHoraInicio() {
        return horaInicio;
    }

    public String getHoraFim() {
        return horaFim;
    }

    public String getDiaSemana() {
        return diaSemana;
    }

    public void setHoraInicio(String horaInicio) {
        this.horaInicio = horaInicio;
    }

    public void setHoraFim(String horaFim) {
        this.horaFim = horaFim;
    }

    public void setDiaSemana(String diaSemana) {
        this.diaSemana = diaSemana;
    }

    public String toString() {
        return "Horario: " + horaInicio + ", " + horaFim + ", " + diaSemana;
    }

    public boolean equals(Horario h) {
        return this.horaInicio.equals(h.getHoraInicio()) && this.horaFim.equals(h.getHoraFim()) && this.diaSemana.equals(h.getDiaSemana());
    }

    public Horario clone() {
        return new Horario(this.horaInicio, this.horaFim, this.diaSemana);
    }
}