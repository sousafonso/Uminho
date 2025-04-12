import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;

public class Youtube{
    private String nome;
    private byte[] conteudo;
    private LocalDate dataCarregamento;
    private int resolucaoX;
    private int resolucaoY;
    private int duracaoMinutos;
    private int duracaoSegundos;
    private ArrayList<String> comentarios;
    private int likes;
    private int dislikes;

    public Youtube (){
        this.nome = "";
        this.conteudo = new byte[0];
        this.dataCarregamento = LocalDate.now();
        this.resolucaoX = 0;
        this.resolucaoY = 0;
        this.duracaoMinutos = 0;
        this.duracaoSegundos = 0;
        this.comentarios = new ArrayList<>();
        this.likes = 0;
        this.dislikes = 0;
    }

    public Youtube (String nome, byte[] conteudo, LocalDate dataCarregamento, int resolucaoX, int resolucaoY, int duracaoMinutos, int duracaoSegundos, ArrayList<String> comentarios, int likes, int dislikes){
        this.nome = nome;
        this.conteudo = conteudo;
        this.dataCarregamento = dataCarregamento;
        this.resolucaoX = resolucaoX;
        this.resolucaoY = resolucaoY;
        this.duracaoMinutos = duracaoMinutos;
        this.duracaoSegundos = duracaoSegundos;
        this.comentarios = comentarios;
        this.likes = likes;
        this.dislikes = dislikes;
    }

    public void setNome (String nome){
        this.nome = nome;
    }

    public void setConteudo (byte[] conteudo){
        this.conteudo = conteudo;
    }

    public void setDataCarregamento (LocalDate dataCarregamento){
        this.dataCarregamento = dataCarregamento;
    }

    public void setResolucaoX (int resolucaoX){
        this.resolucaoX = resolucaoX;
    }

    public void setResolucaoY (int resolucaoY){
        this.resolucaoY = resolucaoY;
    }

    public void setDuracaoMinutos (int duracaoMinutos){
        this.duracaoMinutos = duracaoMinutos;
    }

    public void setDuracaoSegundos (int duracaoSegundos){
        this.duracaoSegundos = duracaoSegundos;
    }

    public void setComentarios (ArrayList<String> comentarios){
        this.comentarios = comentarios;
    }

    public void setLikes (int likes){
        this.likes = likes;
    }

    public void setDislikes (int dislikes){
        this.dislikes = dislikes;
    }

    public String getNome (){
        return this.nome;
    }

    public byte[] getConteudo (){
        return this.conteudo;
    }

    public LocalDate getDataCarregamento (){
        return this.dataCarregamento;
    }

    public int getResolucaoX (){
        return this.resolucaoX;
    }

    public int getResolucaoY (){
        return this.resolucaoY;
    }

    public int getDuracaoMinutos (){
        return this.duracaoMinutos;
    }

    public int getDuracaoSegundos (){
        return this.duracaoSegundos;
    }

    public ArrayList<String> getComentarios (){
        return this.comentarios;
    }

    public int getLikes (){
        return this.likes;
    }

    public int getDislikes (){
        return this.dislikes;
    }

    public void insereComentario (String comentario){
        comentarios.add(comentario);
    }

    public long qtsDiasDepois (){
        return ChronoUnit.DAYS.between(dataCarregamento, LocalDate.now());
    }

    public void thumbsUp(){
        likes++;
    }

    public String processa() {
        // Para fins de teste, retornamos uma string representando o conteúdo do vídeo
        return "Processando conteúdo do vídeo: " + nome;
    }
}