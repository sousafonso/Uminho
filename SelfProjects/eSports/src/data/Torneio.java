package data;
import java.util.Map;

public class Torneio {
    private String id;
    private String nome;
    private String tipo; // e.g. "eFootball", "CS2", "LoL"
    private Map<String, Equipa> equipas;
    private Map<String, Partida> partidas; 
    private Map<Integer, Equipa> classificacao; // e.g. 1 -> "equipa1", 2 -> "equipa2", 3 -> "equipa3"

    public Torneio (String id, String nome, String tipo, Map<String, Equipa> equipas, Map<String, Partida> partidas, Map<Integer, Equipa> classificacao){
        this.id = id;
        this.nome = nome;
        this.tipo = tipo;
        this.equipas = equipas;
        this.partidas = partidas;
        this.classificacao = classificacao;
    }

    public void setID (String id){
        this.id = id;
    }

    public void setNome (String nome){
        this.nome = nome;
    }

    public void setTipo (String tipo){
        this.tipo = tipo;
    }

    public void setEquipas (Map<String, Equipa> equipas){
        this.equipas = equipas;
    }

    public void setPartidas (Map<String, Partida> partidas){
        this.partidas = partidas;
    }

    public void setClassificacao (Map<Integer, Equipa> classificacao){
        this.classificacao = classificacao;
    }

    public String getID (){
        return this.id;
    }

    public String getNome (){
        return this.nome;
    }

    public String getTipo (){
        return this.tipo;
    }

    public Map<String, Equipa> getEquipas (){
        return this.equipas;
    }

    public Map<String, Partida> getPartidas (){
        return this.partidas;
    }

    public Map<Integer, Equipa> getClassificacao (){
        return this.classificacao;
    }

}