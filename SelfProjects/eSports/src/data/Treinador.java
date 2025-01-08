package data;

public class Treinador {
    private String id;
    private Equipa equipa;
    private String nome;
    private String email;
    private String password;

    public Treinador (String id, Equipa equipa, String nome, String email, String password){
        this.id = id;
        this.equipa = equipa;
        this.nome = nome;
        this.email = email;
        this.password = password;
    }

    public void setID (String id){
        this.id = id;
    }

    public void setEquipa (Equipa equipa){
        this.equipa = equipa;
    }

    public void setNome (String nome){
        this.nome = nome;
    }

    public void setEmail (String email){
        this.email = email;
    }

    public void setPassword (String password){
        this.password = password;
    }

    public String getID (){
        return this.id;
    }

    public Equipa getEquipa (){
        return this.equipa;
    }

    public String getNome (){
        return this.nome;
    }

    public String getEmail (){
        return this.email;
    }

    public String getPassword (){
        return this.password;
    }

    public String toString (){
        return "Treinador: " + this.nome + " | ID: " + this.id + " | Email: " + this.email + " | Equipa: " + this.equipa.getNome();
    }
}