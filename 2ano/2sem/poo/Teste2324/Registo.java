import java.io.Serializable;
import java.time.Duration;
import java.time.LocalDate;
import java.util.List;

public class Registo implements Comparable<Registo>, Serializable {
    private int id;
    private LocalDate inicio;
    private LocalDate fim;
    private Quarto quarto;

    public Registo(int id, LocalDate inicio, LocalDate fim, Quarto quarto) {
        this.id = id;
        this.inicio = inicio;
        this.fim = fim;
        this.quarto = quarto;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public LocalDate getInicio() {
        return inicio;
    }
    public void setInicio(LocalDate inicio) {
        this.inicio = inicio;
    }
    public LocalDate getFim() {
        return fim;
    }
    public void setFim(LocalDate fim) {
        this.fim = fim;
    }
    public Quarto getQuarto() {
        return quarto;
    }
    public void setQuarto(Quarto quarto) {
        this.quarto = quarto;
    }

    // Calcula o número de dias da reserva
    public int numDiasReserva() {
        return (int) Duration.between(inicio.atStartOfDay(), fim.atStartOfDay()).toDays();
    }

    // Valor a pagar default: dias reservados * preço por dia do quarto
    public double valorAPagar() {
        return numDiasReserva() * quarto.precoPorDia();
    }

    // Para o caso específico de quartos seniores, o valor a pagar poderá ter desconto adicional.
    // Exemplo: desconto de 25% da soma das idades dos ocupantes.
    public double valorAPagar(List<Integer> idades) {
        double base = numDiasReserva() * quarto.precoPorDia();
        int somaIdades = 0;
        for (int idade : idades) {
            somaIdades += idade;
        }
        double desconto = 0.25 * somaIdades;
        return base - desconto;
    }

    @Override
    public int compareTo(Registo outro) {
        return Integer.compare(this.id, outro.getId());
    }
}