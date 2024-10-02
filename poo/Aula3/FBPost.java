package Aula3;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class FBPost {
    private int id;
    private String utilizador;
    private LocalDateTime instante;
    private String conteudo;
    private int likes;
    private List<String> comentarios;

    public FBPost(int id, String utilizador, int instante, String conteudo, int likes, List<String> comentarios) {
        this.id = id;
        this.utilizador = utilizador;
        this.instante = instante;
        this.conteudo = conteudo;
        this.likes = likes;
        this.comentarios = new ArrayList<>(comentarios);
    }

    public FBPost(FBPost post){
        this.id = post.getId();
        this.utilizador = post.getUtilizador();
        this.instante = post.getInstante();
        this.conteudo = post.getConteudo();
        this.likes = post.getLikes();
        this.comentarios = post.getComentarios();
    }

    public int getId() {
        return this.id;
    }

    public String getUtilizador() {
        return this.utilizador;
    }

    public int getInstante() {
        return this.instante;
    }

    public String getConteudo() {
        return this.conteudo;
    }

    public int getLikes() {
        return this.likes;
    }

    public List<String> getComentarios() {
        return new ArrayList<>(this.comentarios);
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setUtilizador(String utilizador) {
        this.utilizador = utilizador;
    }

    public void setInstante(int instante) {
        this.instante = instante;
    }

    public void setConteudo(String conteudo) {
        this.conteudo = conteudo;
    }

    public void setLikes(int likes) {
        this.likes = likes;
    }

    public void setComentarios(List<String> comentarios) {
        this.comentarios = new ArrayList<>(comentarios);
    }

    public void addComment(String comment) {
        this.comments.add(comment);
    }

    public voi addLike() {
        likes ++;
    }
}
