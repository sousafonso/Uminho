package Semana3;

import java.time.LocalDateTime;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.List;


public class Video {
    String codigo;
    String nome;
    byte[] conteudo;
    LocalDate data;
    String resolucao;
    LocalTime duracao;
    List<String> comentarios;
    int likes;
    int dislikes;

    public Video (){
        this.codigo = "";
        this.nome = "";
        this.conteudo = null;
        this.data = LocalDate.now();
        this.resolucao = "";
        this.duracao = LocalTime.of(0,0);
        this.comentarios = null;
        this.likes = 0;
        this.dislikes = 0;
    }

    public Video (String codigo, String nome, byte[] conteudo, LocalDate data, String resolucao, LocalTime duracao, List <String> comentarios, int likes, int dislikes){
        this.codigo = codigo;
        this.nome = nome;
        this.conteudo = conteudo;
        this.data = data;
        this.resolucao = resolucao;
        this.duracao = duracao;
        this.comentarios = comentarios;
        this.likes = likes;
        this.dislikes = dislikes;
    }

    public Video (Video v){
        this.codigo = v.codigo;
        this.nome = v.nome;
        this.conteudo = v.conteudo;
        this.data = v.data;
        this.resolucao = v.resolucao;
        this.duracao = v.duracao;
        this.comentarios = v.comentarios;
        this.likes = v.likes;
        this.dislikes = v.dislikes;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public byte[] getConteudo() {
        return conteudo;
    }

    public void setConteudo(byte[] conteudo) {
        this.conteudo = conteudo;
    }

    public LocalDate getData() {
        return data;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public String getResolucao() {
        return resolucao;
    }

    public void setResolucao(String resolucao) {
        this.resolucao = resolucao;
    }

    public LocalTime getDuracao() {
        return duracao;
    }

    public void setDuracao(LocalTime duracao) {
        this.duracao = duracao;
    }

    public List<String> getComentarios() {
        return comentarios;
    }

    public void setComentarios(List<String> comentarios) {
        this.comentarios = comentarios;
    }

    public int getLikes() {
        return likes;
    }

    public void setLikes(int likes) {
        this.likes = likes;
    }

    public int getDislikes() {
        return dislikes;
    }

    public void setDislikes(int dislikes) {
        this.dislikes = dislikes;
    }

    @Override
    public String toString() {
        return "Video{" +
                "codigo='" + codigo + '\'' +
                "nome='" + nome + '\'' +
                ", conteudo=" + conteudo +
                ", data=" + data +
                ", resolucao='" + resolucao + '\'' +
                ", duracao=" + duracao +
                ", comentarios=" + comentarios +
                ", likes=" + likes +
                ", dislikes=" + dislikes +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Video)) return false;

        Video video = (Video) o;

        if (likes != video.likes) return false;
        if (dislikes != video.dislikes) return false;
        if (!codigo.equals(video.codigo)) return false;
        if (!nome.equals(video.nome)) return false;
        if (!data.equals(video.data)) return false;
        if (!resolucao.equals(video.resolucao)) return false;
        if (!duracao.equals(video.duracao)) return false;
        return comentarios.equals(video.comentarios);
    }
    @Override

    public Video clone() {
        return new Video(this);
    }

    public void insereComentario(String comentario){
        comentarios.add(comentario);
    }

    public long qtsDiasDepois(){
        LocalDateTime agora = LocalDateTime.now();
        long dias = java.time.Duration.between(data, agora).toDays();
        return dias;
    }

    public void thumbsUp(){
        this.likes++;
    }

    public String processa() {
        if (conteudo == null || conteudo.length == 0) {
            return "";
        }
        byte[] bytes = new byte[conteudo.length];
        for (int i = 0; i < conteudo.length; i++) {
            bytes[i] = conteudo[i];
        }
        return new String(bytes, java.nio.charset.StandardCharsets.UTF_8);
    }

}
