package Teste2425;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Utilizador implements Comparable<Utilizador>, Serializable {
    private static int proximoId = 1;
    private int idCliente;
    private String nome;
    private String morada;
    private List<Registo> registos;

    public Utilizador(String nome, String morada) {
        this.idCliente = proximoId++;
        this.nome = nome;
        this.morada = morada;
        this.registos = new ArrayList<>();
    }

    public double valorTotalGasto() {
        return registos.stream().mapToDouble(Registo::valorAPagar).sum();
    }

    public List<Registo> getRegistos() {
        return new ArrayList<>(registos);
    }

    @Override
    public int compareTo(Utilizador o) {
        double diff = o.valorTotalGasto() - this.valorTotalGasto();
        if (diff != 0) {
            return diff > 0 ? 1 : -1;
        }
        return this.registos.size() - o.registos.size();
    }
}