package Teste2324;

import java.time.LocalDate;
import java.util.HashMap;
import java.util.Map;

public class Hotel {
    private String nome;
    Map<String, Quarto> quartos;
    private Map<Integer, Registo> registos;

    public Hotel(String nome, Map<String, Quarto> quartos) {
        this.nome = nome;
        this.quartos = quartos;
        this.registos = new HashMap<>();
    }

    /**
     * Construtor que recebe um iterador de quartos
     * @param quartos
     */
    public Hotel(Iterator<Quarto> quartos) {
        this.quartos = new HashMap<>();
        this.registos = new HashMap<>();
        while (quartos.hasNext()) {
            Quarto quarto = quartos.next();
            this.quartos.put(quarto.getNumeroQuarto(), quarto);
        }
    }

    /**
     * Método que adiciona uma reserva
     * @param entrada
     * @param saida
     * @param numQuarto
     */
    public void adicionaRegisto(LocalDate entrada, LocalDate saida, String numQuarto) {
        if (quartos.containsKey(numQuarto)) {
            int novoNumeroRegisto = registos.size() + 1; // Número do registo sequencial
            Registo novoRegisto = new Registo(novoNumeroRegisto, entrada, saida, numQuarto);
            registos.put(novoNumeroRegisto, novoRegisto);
        } else {
            // Caso o quarto não exista, pode lançar uma exceção ou tratar o erro conforme necessário
            System.out.println("Quarto não encontrado.");
        }
    }

    
}
