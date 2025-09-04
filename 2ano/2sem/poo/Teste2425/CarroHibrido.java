package Teste2425;

import java.io.Serializable;

public class CarroHibrido extends Carro implements Serializable {
    private double tamanhoDeposito; // Litros
    private double consumoCombustivel; // Litros/100km
    private double precoLitro;
    private double tamanhoBateria; // kWh
    private double consumoEletrico; // kWh/100km
    private double precoKwh;

    public CarroHibrido(String matricula, double tamanhoDeposito, double consumoCombustivel, double precoLitro,
                        double tamanhoBateria, double consumoEletrico, double precoKwh) {
        super(matricula);
        this.tamanhoDeposito = tamanhoDeposito;
        this.consumoCombustivel = consumoCombustivel;
        this.precoLitro = precoLitro;
        this.tamanhoBateria = tamanhoBateria;
        this.consumoEletrico = consumoEletrico;
        this.precoKwh = precoKwh;
    }

    @Override
    public double valorPorDia() {
        // Exemplo: média dos custos de combustão e elétrico
        return (consumoCombustivel * precoLitro + consumoEletrico * precoKwh) / 2;
    }

    public double getTamanhoBateria() {
        return tamanhoBateria;
    }
}