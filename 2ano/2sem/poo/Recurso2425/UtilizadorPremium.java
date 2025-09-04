package Recurso2425;

import java.util.ArrayList;
import java.util.List;

public class UtilizadorPremium extends Utilizador {
    private static final int MAX_EPISODIOS = 20;
    private List<Episodio> episodiosLocais;
    
    public UtilizadorPremium(String nomeUtilizador, List<String> nomesPodcasts) {
        super(nomeUtilizador, nomesPodcasts);
        this.episodiosLocais = new ArrayList<>();
    }
    
    public void guardaLocalmente(Episodio e) throws NaoExisteEspacoException {
        if (episodiosLocais.size() >= MAX_EPISODIOS) throw new NaoExisteEspacoException();
        episodiosLocais.add(e);
    }
}
