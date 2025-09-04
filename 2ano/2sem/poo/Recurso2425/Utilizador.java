package Recurso2425;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Utilizador {
    private static int numeroUtilizador = 1;
    private String nome;
    private Set<String> podcastsSeguidos; // Nomes dos podcasts seguidos
    private List<Registo> historico; // Histórico de episódios ouvidos

    public Utilizador(String nomeUtilizador, List<String> nomesPodcasts) {
        this.numeroUtilizador = PodCastUM.getProximoNumeroUtilizador();
        this.nome = nomeUtilizador;
        this.podcastsSeguidos = new HashSet<>(nomesPodcasts);
        this.historico = new ArrayList<>();
    }

    public Utilizador (int numero, String nomeUtilizador, List<String> podcastsSubscritos, List<Registo> registos){
        this.numeroUtilizador = numero;
        this.nome = nomeUtilizador;
        this.podcastsSeguidos = Set.copyOf(podcastsSubscritos);
        this.historico = new ArrayList<>(registos);
    }

    public List<Registo> getHistorico() {
        return new ArrayList<>(historico);
    }

    public void adicionaPodCast(PodCast p){}

    public void ouvirEpisodio(PodCast pod, int numEpisodio, int numMinutosEscutados) 
        throws EpisodioNaoExisteException {
        
        // Verificar se o episódio existe
        if (numEpisodio < 1 || numEpisodio > pod.getEpisodios().size()) {
            throw new EpisodioNaoExisteException(numEpisodio);
        }
        
        Episodio ep = pod.getEpisodios().get(numEpisodio - 1);
        Registo novoRegisto = new Registo(ep, LocalDate.now(), numMinutosEscutados);
        historico.add(novoRegisto);
    }
}
