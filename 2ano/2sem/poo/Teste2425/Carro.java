package Teste2425;

import java.io.Serializable;

public abstract class Carro implements Serializable, Cloneable {
    private String matricula;

    public Carro(String matricula) {
        this.matricula = matricula;
    }

    public String getMatricula() { return matricula; }

    public abstract double valorPorDia(int kmsPorDia);

    @Override
    public Carro clone() {
        try {
            return (Carro) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new AssertionError();
        }
    }
}
