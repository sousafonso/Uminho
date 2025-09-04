import java.io.Serializable;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Registo implements Comparable<Registo>, Serializable {
    private static int proximoId = 1;
    private int numeroRegisto;
    private LocalDate dataInicio;
    private LocalDate dataFim;
    private Quarto quarto;
    private int[] idadesOcupantes; // Para suportar desconto senior

    public Registo(LocalDate dataInicio, LocalDate dataFim, Quarto quarto) {
        this(dataInicio, dataFim, quarto, null);
    }

    public Registo(LocalDate dataInicio, LocalDate dataFim, Quarto quarto, int[] idades) {
        this.numeroRegisto = proximoId++;
        this.dataInicio = dataInicio;
        this.dataFim = dataFim;
        this.quarto = quarto.clone();
        this.idadesOcupantes = idades != null ? idades.clone() : null;
    }

    public int numDiasReserva() {
        return (int) ChronoUnit.DAYS.between(dataInicio, dataFim) + 1;
    }

    public double valorAPagar() {
        double precoBase = quarto.precoPorDia() * numDiasReserva();
        if (quarto instanceof QuartoDuploSenior && idadesOcupantes != null) {
            int somaIdades = idadesOcupantes[0] + idadesOcupantes[1];
            double desconto = precoBase * (0.25 * somaIdades / 100);
            return precoBase - desconto;
        }
        return precoBase;
    }

    @Override
    public int compareTo(Registo o) {
        return Integer.compare(this.numeroRegisto, o.numeroRegisto);
    }

    public LocalDate getDataInicio() {
        return dataInicio;
    }

    public LocalDate getDataFim() {
        return dataFim;
    }
}