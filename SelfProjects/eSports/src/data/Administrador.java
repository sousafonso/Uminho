package data;

public class Administrador {
    private String id;
    private String nome;
    private String email;
    private String password;

    public Administrador (String id, String nome, String email, String password){
        this.id = id;
        this.nome = nome;
        this.email = email;
        this.password = password;
    }

    public void setID (String id){
        this.id = id;
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

    public String getNome (){
        return this.nome;
    }

    public String getEmail (){
        return this.email;
    }

    public String getPassword() {
        return this.password;
    }

    public String toString (){
        return "Administrador: " + this.nome + " | ID: " + this.id + " | Email: " + this.email;
    }
}