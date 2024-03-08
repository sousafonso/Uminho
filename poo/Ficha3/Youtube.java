import javax.xml.crypto.Data;

public class Youtube{
    private String nome;
    private Integer conteudo;
    private Data data;
    private String [] comentarios;
    private Integer duracao;
    private Integer likes;
    private Integer deslikes;
    private Integer resolucao;

    public Youtube(String nome, Integer conteudo, Data data, String[] comentarios, Integer duracao, Integer likes, Integer deslikes, Integer resolucao){
        this.nome = nome;
        this.conteudo = conteudo;
        this.data = data;
        this.comentarios = comentarios;
        this.duracao = duracao;
        this.likes = likes;
        this.deslikes = deslikes;
        this.resolucao = resolucao;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return this.nome;
    }

    public void setConteudo(Integer conteudo){
        this.conteudo = conteudo;
    }

    public Integer getConteudo(){
        return this.conteudo;
    }

    public void setData(Data data){
        this.data = data;
    }

    public Data getData(){
        return this.data;
    }

    public void setComentarios(String[] comentarios){
        this.comentarios = comentarios;
    }

    public String[] getComentarios(){
        return this.comentarios;
    }

    public void setDuracao(Integer duracao){
        this.duracao = duracao;
    }

    public Integer getDuracao(){
        return this.duracao;
    }

    public void setLikes(Integer likes){
        this.likes = likes;
    }

    public Integer getLikes(){
        return this.likes;
    }

    public void setDeslikes(Integer deslikes){
        this.deslikes = deslikes;
    }

    public Integer getDeslikes(){
        return this.deslikes;
    }

    public void setResolucao(Integer resolucao){
        this.resolucao = resolucao;
    }

    public Integer getResolucao(){
        return this.resolucao;
    }

    public void adicionarComentario(String comentario){
        for(int i = 0; i < this.comentarios.length; i++){
            if(this.comentarios[i] == null){
                this.comentarios[i] = comentario;
                break;
            }
        }
    }

    public void removerComentario(String comentario){
        for(int i = 0; i < this.comentarios.length; i++){
            if(this.comentarios[i] == comentario){
                this.comentarios[i] = null;
                break;
            }
        }
    }

    public void thumbsUp(){
        this.likes++;
    }

    public void darDeslike(){
        this.deslikes++;
    }

    public void alterarResolucao(Integer resolucao){
        this.resolucao = resolucao;
    }

    public void alterarDuracao(Integer duracao){
        this.duracao = duracao;
    }

    public void alterarConteudo(Integer conteudo){
        this.conteudo = conteudo;
    }

    public void alterarNome(String nome){
        this.nome = nome;
    }

    public void alterarData(Data data){
        this.data = data;
    }

    public void mostrarDados(){
        System.out.println("Nome: " + this.nome);
        System.out.println("Conteudo: " + this.conteudo);
        System.out.println("Data: " + this.data);
        System.out.println("Comentarios: " + this.comentarios);
        System.out.println("Duracao: " + this.duracao);
        System.out.println("Likes: " + this.likes);
        System.out.println("Deslikes: " + this.deslikes);
        System.out.println("Resolucao: " + this.resolucao);
    }

    public void insereComentario(String comentario){
        for(int i = 0; i < this.comentarios.length; i++){
            if(this.comentarios[i] == null){
                this.comentarios[i] = comentario;
                break;
            }
        }
    }

    public long qtsDiasDepois() {
        long dias = 0;
        return dias;
    }
}