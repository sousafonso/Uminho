package Teste2425;

import java.io.Serializable;
import java.time.LocalDate;

public class Registo implements Comparable<Registo>, Serializable {
    private Carro carro; // apenas referência!
    private LocalDate dataInicio;
    private LocalDate dataFim;
    private int kmsContratados;

    public Registo(Carro carro, LocalDate dataInicio, LocalDate dataFim, int kmsContratados) {
        this.carro = carro;
        this.dataInicio = dataInicio;
        this.dataFim = dataFim;
        this.kmsContratados = kmsContratados;
    }

    // Clone: shallow copy do carro
    public Registo(Registo outro) {
        this.carro = outro.carro; // apenas referência!
        this.dataInicio = outro.dataInicio;
        this.dataFim = outro.dataFim;
        this.kmsContratados = outro.kmsContratados;
    }

    public int getDias() {
        return (int) (java.time.temporal.ChronoUnit.DAYS.between(dataInicio, dataFim) + 1);
    }

    public int getKmsPorDia() {
        return kmsContratados / getDias();
    }

    @Override
    public int compareTo(Registo o) {
        return this.dataInicio.compareTo(o.dataInicio);
    }
}