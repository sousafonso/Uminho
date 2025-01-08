package Aula4;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class Parque {
   private String nome;
   Map<String, Lugar> lugares; 

   public Parque(String nome, String informacao, String matricula) {
        this.nome = nome;
        this.lugares = new HashMap<>();
    }
   
   public void setNome(String nome){
    this.nome = nome;
   }

   public String getNome(){
    return this.nome;
   }

    public Set<String> getMatriculas() {
        return new HashSet<>(lugares.keySet());
    }

    public void setOcupacao (String informacao, String matricula){
        lugares.put(informacao, matricula);
    }

    public void removeLugar(String matricula){
        lugares.remove(l);
    }

    /**
     * Método que altera o tempo de um lugar
     * @param tempo
     * @param matricula
     */
    public void alteraTempo (int tempo, String matricula){
        Lugar lugar = lugares.get(matricula);
        if (lugar != null) {
            lugar.setTempo(novoTempo);
        }
    }

    /**
     * Método que devolve o total de minutos atribuídos no estacionamento
     * @return
     */
    public int totalMinutosAtribuidos() {
        return lugares.values().stream().mapToInt(Lugar::getTempo).sum();
    }

    /**
     * Método que verifica se existe um lugar ocupado com uma dada matrícula
     * @param matricula
     * @return
     */
    public boolean existeLugar (String matricula){
        return lugares.containsKey(matricula);
    }

    /**
     * Método que devolve a lista de matrículas dos lugares ocupados por mais de x minutos
     * @param x
     * @return
     */
    public List<String> matriculas (int x){
        return lugares.entrySet().stream()
                .filter(entry -> entry.getValue().getTempo() > x && entry.getValue().isPermanente())
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());
    }

    public Map<String, Lugar> copiaLugares() {
        return new HashMap<>(lugares);
    }

    public String returnInformacao(String matricula){
        Lugar lugar = lugares.get(matricula);
        return lugar.getInformacao()
    }
}