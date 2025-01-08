package data;

public class JogadorMOBA extends Jogador {
    private String personagem;
    private int kills;
    private int deaths;
    private int assists;

    public JogadorMOBA (String id, String nome, String nickname, int partidas, int jogadas, int vitorias, int derrotas, String password, String personagem, int kills, int deaths, int assists, String username){
        super(id, nome, nickname, partidas, jogadas, vitorias, derrotas, password, username);
        this.personagem = personagem;
        this.kills = kills;
        this.deaths = deaths;
        this.assists = assists;
    }

    public void setPersonagem (String personagem){
        this.personagem = personagem;
    }

    public void setKills (int kills){
        this.kills = kills;
    }

    public void setDeaths (int deaths){
        this.deaths = deaths;
    }

    public void setAssists (int assists){
        this.assists = assists;
    }

    public String getPersonagem (){
        return this.personagem;
    }

    public int getKills (){
        return this.kills;
    }

    public int getDeaths (){
        return this.deaths;
    }

    public int getAssists (){
        return this.assists;
    }
}