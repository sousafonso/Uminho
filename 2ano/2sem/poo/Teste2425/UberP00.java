package Teste2425;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class UberP00 implements Serializable {
    private String nomeComercial;
    private Map<String, Carro> carros;
    private Map<Integer, Utilizador> utilizadores;

    public UberP00(Collection<Carro> carros) {
        this.nomeComercial = "UberP00";
        this.carros = new HashMap<>();
        for (Carro c : carros) {
            this.carros.put(c.getMatricula(), c.clone());
        }
        this.utilizadores = new HashMap<>();
    }

    public void adicionaRegisto(LocalDate inicio, LocalDate fim, String matricula, int idUtilizador, int kmsContratados) 
            throws IllegalArgumentException {
        if (!carros.containsKey(matricula)) {
            throw new IllegalArgumentException("Carro com matrícula " + matricula + " não existe.");
        }
        if (!utilizadores.containsKey(idUtilizador)) {
            throw new IllegalArgumentException("Utilizador com ID " + idUtilizador + " não existe.");
        }
        if (inicio.isAfter(fim)) {
            throw new IllegalArgumentException("Data de início não pode ser posterior à data de fim.");
        }
        if (kmsContratados <= 0) {
            throw new IllegalArgumentException("Número de quilómetros contratados deve ser positivo.");
        }

        Carro carro = carros.get(matricula);
        Registo registo = new Registo(carro, inicio, fim, kmsContratados);
        utilizadores.get(idUtilizador).getRegistos().add(registo);
    }

    public Utilizador utilizadorMaisGastador() {
        return utilizadores.values().stream()
                .max(Utilizador::compareTo)
                .orElse(null);
    }

    public List<CarroHibrido> getHibridos() {
        return carros.values().stream()
                .filter(c -> c instanceof CarroHibrido)
                .map(c -> (CarroHibrido) c) // Transformar o tipo genérico para a subclasse
                .sorted((c1, c2) -> Double.compare(c1.getTamanhoBateria(), c2.getTamanhoBateria()))
                .collect(Collectors.toList());
    }

    public List<CarroHibrido> getHibridosReversed(){
        return carros.values().stream()
                .filter(c -> c instanceof CarroHibrido)
                .map(c -> (CarroHibrido) c) // Transformar o tipo genérico para a subclasse
                .sorted(Comparator.comparingDouble(CarroHibrido::getTamanhoBateria).reversed())
                .collect(Collectors.toList());
    }
}