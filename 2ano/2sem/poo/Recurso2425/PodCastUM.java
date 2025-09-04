package Recurso2425;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class PodCastUM {
    private Map<String, PodCast> podcasts; // Nome PodCast -> PodCast
    private Map<Integer, Utilizador> utilizadores;

    public PodCastUM() {
        this.podcasts = new HashMap<>();
        this.utilizadores = new HashMap<>();
    }

    public void subscrevePodCast(int numUtilizador, String nomePodcast) throws IllegalArgumentException{
        if(!podcasts.containsKey(nomePodcast)) throw new IllegalArgumentException();
        if(!utilizadores.containsKey(numUtilizador)) throw new IllegalArgumentException();
        Utilizador u = utilizadores.get(numUtilizador);
        u.adicionaPodCast(podcasts.get(nomePodcast));
    }

    public String podCastMaisExecutado() {
        return podcasts.entrySet().stream()
                .max((e1, e2) -> {
                    int minutos1 = e1.getValue().getEpisodios().stream()
                            .mapToInt(ep -> ep.getDuracao())
                            .sum();
                    int minutos2 = e2.getValue().getEpisodios().stream()
                            .mapToInt(ep -> ep.getDuracao())
                            .sum();
                    if (minutos1 != minutos2) {
                        return Integer.compare(minutos1, minutos2);
                    }
                    return e2.getKey().compareTo(e1.getKey()); // Desempate alfabético
                })
                .map(Map.Entry::getKey)
                .orElse(null);
    }

}
