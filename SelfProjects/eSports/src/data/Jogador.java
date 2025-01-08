package data;

public class Jogador {
    private String id;
    private String nome;
    private String nickname;
    private int npartidas;
    private int njogadas;
    private int nvitorias;
    private int nderrotas;
    private String password;
    private String username;

    public Jogador (String id, String nome, String nickname, int partidas, int jogadas, int vitorias, int derrotas, String password, String username){
        this.id = id;
        this.nome = nome;
        this.nickname = nickname;
        this.npartidas = partidas;
        this.nvitorias = vitorias;
        this.nderrotas = derrotas;
        this.njogadas = jogadas;
        this.password = password;
        this.username = username;
    }

    public void setID (String id){
        this.id = id;
    }
    
    public void setNome (String nome){
        this.nome = nome;
    }

    public void setNickname (String nickname){
        this.nickname = nickname;
    }

    public void setPartidas (int partidas){
        this.npartidas = partidas;
    }

    public void setJogadas (int jogadas){
        this.njogadas = jogadas;
    }

    public void setVitorias (int vitorias){
        this.nvitorias = vitorias;
    }

    public void setDerrotas (int derrotas){
        this.nderrotas = derrotas;
    }

    public void setPassword (String password){
        this.password = password;
    }

    public void setUsername (String username){
        this.username = username;
    }

    public String getID (){
        return this.id;
    }

    public String getNome (){
        return this.nome;
    }

    public String getNickname (){
        return this.nickname;
    }

    public int getPartidas (){
        return this.npartidas;
    }

    public int getJogadas (){
        return this.njogadas;
    }

    public int getVitorias (){
        return this.nvitorias;
    }

    public int getDerrotas (){
        return this.nderrotas;
    }

    public String getPassword (){
        return this.password;
    }

    public String getUsername (){
        return this.username;
    }
}
