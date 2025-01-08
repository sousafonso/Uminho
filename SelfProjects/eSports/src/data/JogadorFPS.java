package data;

public class JogadorFPS extends Jogador {
    private double precisao;
    private int headshots;

    public JogadorFPS (String id, String nome, String nickname, int partidas, int jogadas, int vitorias, int derrotas, String password, double precisao, int headshots, String username){
        super(id, nome, nickname, partidas, jogadas, vitorias, derrotas, password, username);
        this.precisao = precisao;
        this.headshots = headshots;
    }

    public void setPrecisao (double precisao){
        this.precisao = precisao;
    }

    public void setHeadshots (int headshots){
        this.headshots = headshots;
    }

    public double getPrecisao (){
        return this.precisao;
    }

    public int getHeadshots (){
        return this.headshots;
    }
}