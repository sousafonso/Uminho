import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;

public class HoteisPOO implements Serializable {
    private Map<String, Hotel> hoteis;
    
    public HoteisPOO(Map<String, Hotel> hoteis) {
        this.hoteis = hoteis;
    }
    
    public List<String> hoteisMaisOcupados() {
        List<Hotel> lista = new ArrayList<>(hoteis.values());
        // Ordena por total de dias (descendente) e, em caso de empate, pelo nome (alfabeticamente maior)
        Collections.sort(lista, new Comparator<Hotel>() {
            @Override
            public int compare(Hotel h1, Hotel h2) {
                int dif = h2.getTotalDiasOcupacao() - h1.getTotalDiasOcupacao();
                if (dif == 0) {
                    return h2.getNome().compareTo(h1.getNome());
                }
                return dif;
            }
        });
        List<String> resultado = new ArrayList<>();
        for (int i = 0; i < Math.min(3, lista.size()); i++){
            resultado.add(lista.get(i).getNome());
        }
        return resultado;
    }
}