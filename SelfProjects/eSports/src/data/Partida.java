package data;

import java.time.LocalDate;

public class Partida {
    private String id;
    private String equipaA;
    private String equipaB;
    private LocalDate data;
    private int [] pontos; // pontos[0] -> equipaA; pontos[1] -> equipaB

    public Partida (String id, String equipaA, String equipaB, LocalDate data, int [] pontos){
        this.id = id;
        this.equipaA = equipaA;
        this.equipaB = equipaB;
        this.data = data;
        this.pontos = pontos;
    }

    public void setID (String id){
        this.id = id;
    }

    public void setEquipaA (String equipaA){
        this.equipaA = equipaA;
    }

    public void setEquipaB (String equipaB){
        this.equipaB = equipaB;
    }

    public void setData (LocalDate data){
        this.data = data;
    }

    public void setPontos (int [] pontos){
        this.pontos = pontos;
    }

    public String getID (){
        return this.id;
    }

    public String getEquipaA (){
        return this.equipaA;
    }

    public String getEquipaB (){
        return this.equipaB;
    }

    public LocalDate getData (){
        return this.data;
    }

    public int [] getPontos (){
        return this.pontos;
    }
}