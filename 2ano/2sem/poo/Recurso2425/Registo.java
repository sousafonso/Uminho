package Recurso2425;

import java.io.Serializable;
import java.time.LocalDate;

public class Registo implements Comparable<Registo>, Serializable {
    private Episodio episodio;
    private LocalDate data;
    private int tempo;

    public Registo(Episodio ep, LocalDate now, int numMinutosEscutados) {
        this.episodio = ep;
        this.data = now;
        this.tempo = numMinutosEscutados;
    }

    public int getDuracao(){
        return this.tempo;
    }

    public Object getEpisodio() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'getEpisodio'");
    }
}
