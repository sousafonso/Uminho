import java.io.Serializable;
import java.time.LocalDate;

public class Registo implements Comparable<Registo>, Serializable {
    private String numeroQuarto;
    private LocalDate data_inicio;
    private LocalDate data_fim;
    private int num_registo;

    public Registo(int num_registo, LocalDate data_inicio, LocalDate data_fim, String numeroQuarto) {
        this.num_registo = num_registo;
        this.data_inicio = data_inicio;
        this.data_fim = data_fim;
        this.numeroQuarto = numeroQuarto;
    }
}