package Recurso2324;

import java.io.Serializable;

public class Corrida extends Atividade implements Comparable<Corrida>, Serializable, TemMetros {
    private double distancia;
    private double altimetria;

    public double getDistancia(){
        return this.distancia;
    }

    public double calcularPontos(){
        return distancia * altimetria;
    }

}
