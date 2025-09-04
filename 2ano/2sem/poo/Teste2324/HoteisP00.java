import java.io.Serializable;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class HoteisP00 implements Serializable {
    private Map<String, Hotel> hoteis;

    public HoteisP00() {
        this.hoteis = new HashMap<>();
    }

    public List<String> hoteisMaisOcupados() {
        return hoteis.entrySet().stream()
                .sorted((e1, e2) -> {
                    int dias1 = e1.getValue().getRegistos().stream().mapToInt(Registo::numDiasReserva).sum();
                    int dias2 = e2.getValue().getRegistos().stream().mapToInt(Registo::numDiasReserva).sum();
                    if (dias1 != dias2) {
                        return Integer.compare(dias2, dias1); // Maior número de dias primeiro
                    }
                    return e2.getKey().compareTo(e1.getKey()); // Nome alfabeticamente maior
                })
                .limit(3)
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());
    }
}