package data;

public class JogadorEFootball extends Jogador { 
    private String posicao;
    private int golos;

    public JogadorEFootball (String id, String nome, String nickname, int partidas, int jogadas, int vitorias, int derrotas, String password, String posicao, int golos, String username){
        super(id, nome, nickname, partidas, jogadas, vitorias, derrotas, password, username);
        this.posicao = posicao;
        this.golos = golos;
    }

    public void setPosicao (String posicao){
        this.posicao = posicao;
    }

    public void setGolos (int golos){
        this.golos = golos;
    }

    public String getPosicao (){
        return this.posicao;
    }

    public int getGolos (){
        return this.golos;
    }
}