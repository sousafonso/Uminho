package data;
import java.util.Map;

public class Equipa {
    private String id;
    private String nome;
    private Map<String, Jogador> jogadores;
    private int vitorias;
    private int derrotas;

    public Equipa (String id, String nome, Map<String, Jogador> jogadores, int vitorias, int derrotas){
        this.id = id;
        this.nome = nome;
        this.jogadores = jogadores;
        this.vitorias = vitorias;
        this.derrotas = derrotas;
    }

    public void setID (String id){
        this.id = id;
    }

    public void setNome (String nome){
        this.nome = nome;
    }

    public void setJogadores (Map<String, Jogador> jogadores){
        this.jogadores = jogadores;
    }

    public void setVitorias (int vitorias){
        this.vitorias = vitorias;
    }

    public void setDerrotas (int derrotas){
        this.derrotas = derrotas;
    }

    public String getID (){
        return this.id;
    }

    public String getNome (){
        return this.nome;
    }

    public Map<String, Jogador> getJogadores (){
        return this.jogadores;
    }

    public int getVitorias (){
        return this.vitorias;
    }

    public int getDerrotas (){
        return this.derrotas;
    }
}