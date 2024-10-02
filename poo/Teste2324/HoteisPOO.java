import java.io.Serializable;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class HoteisPOO implements Serializable {
    private Map<String, Hotel> hoteis;

    public HoteisPOO(Map<String, Hotel> hoteis) {
        this.hoteis = hoteis;
    }

    public HoteisPOO() {
        this.hoteis = new HashMap<>();
    }

    public void adicionaHotel(Hotel h) {
        hoteis.put(h.getNome(), h);
    }

    public void adicionaReserva(String nomeHotel, Registo r) {
        hoteis.get(nomeHotel).adicionaReserva(r);
    }

    public int calcularDiasOcupados(Hotel h) {
        return h.getRegistos().stream()
                .mapToInt(r -> r.getData_inicio().until(r.getData_fim()).getDays())
                .sum();
    }

    /**
     * Método que devolve os nomes dos 3 hotéis com mais dias ocupados
     * @return
     */
    public List<String> hoteisMaisOcupados(){
        return hoteis.values().stream() // stream() é um método que devolve um stream de elementos
                .sorted(Comparator.comparingInt(this::calcularDiasOcupados).reversed()
                        .thenComparing(Hotel::getNome))
                .limit(3)
                .map(Hotel::getNome)
                .collect(Collectors.toList());
    }
}

/**
 * sorted() - ordena os elementos do stream
 * Comparator.comparingInt(this::calcularDiasOcupados) - compara os elementos do stream com base no número de dias ocupados
 * reversed() - inverte a ordem de ordenação
 * thenComparing(Hotel::getNome) - compara os elementos do stream com base no nome do hotel
 * limit(3) - limita o stream aos primeiros 3 elementos
 * map(Hotel::getNome) - mapeia os elementos do stream para os nomes dos hotéis
 * collect(Collectors.toList()) - coleta os elementos do stream numa lista
 */