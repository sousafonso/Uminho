import java.util.List;
import java.util.Set;
import java.util.ArrayList;
import java.util.stream.Collectors;

/**
 * @author Afonso Sousa
 * @category Funções predefinidas da linguagem
 * 
 * add - adiciona 
 * get - obter
 * set - definir
 * remove - remover
 * clone - clonar
 * equals - comparar
 * forEach - para cada elemento do stream
 * collect - colecionar
 * stream - sequência de elementos
 * map - mapear
 * filter - filtrar
 * count - contar 
 */
public class CasaInteligente {
    private List <Lampada> lampadas;

    /**
     * @brief Construtor vazio
     * Inicializa a lista de lampadas
     */
    public CasaInteligente() {
        lampadas = new ArrayList<Lampada>();
    }

    /**
     * @brief Construtor por cópia
     * Serve para criar uma nova casa inteligente a partir de uma já existente
     * @param lampadas
     */
    public CasaInteligente(List<Lampada> lampadas) {
        this.lampadas = lampadas.stream().map(Lampada::clone).collect(Collectors.toList());
    }

    /**
     * @brief Método que adiciona uma lampada 
     * @param lampada
     */
    public void addLampada(Lampada lampada) {
        lampadas.add(lampada.clone());
    }

    /**
     * @brief Método que liga uma lampada normal
     * @param index
     */
    public void ligaLampadaNormal(int index) {
        lampadas.get(index).lampON();
    }

    /**
     * @brief Método que liga uma lampada em modo eco
     * @param index
     */
    public void ligaLampadaEco(int index) {
        lampadas.get(index).lampECO();
    }

    /**
     * @brief Método que desliga uma lampada
     * @param index
     */
    public int qtEmEco() {
        return (int) lampadas.stream().filter(Lampada::getEstado).count();
    }

    /**
     * @brief Método que desliga uma lampada
     * @param index
     */
    public void desligaLampada(int index) {
        lampadas.get(index).lampOFF();
    }

    /**
     * @brief Método que remove uma lampada
     * @param index
     */
    public void removeLampada(int index) {
        lampadas.remove(index);
    }

    /**
     * @brief Método que liga todas as lampadas em modo eco
     */
    public void ligaTodasEco() {
        lampadas.forEach(Lampada::lampECO);
    }

    /**
     * @brief Método que liga todas as lampadas em modo consumo máximo
     */
    public void ligaTodasMax() {
        lampadas.forEach(Lampada::lampON);
    }

    /**
     * @brief Método que calcula o consumo total de todas as lampadas
     * @return consumo total
     */
    public double consumoTotal() {
        return lampadas.stream().mapToDouble(Lampada::getConsumo).sum();
    }

    /**
     * @brief Método que devolve uma lista com todas as lampadas
     * @return lista de lampadas
     */
    public List<Lampada> getLampadas() {
        return lampadas.stream().map(Lampada::clone).collect(Collectors.toList());
    }   

    /**
     * @brief Método que define a lista de lampadas
     * @param lampadas
     */
    public void setLampadas(List<Lampada> lampadas) {
        this.lampadas = lampadas.stream().map(Lampada::clone).collect(Collectors.toList());
    }

    /**
     * @brief Método que devolve a lampada mais gastadora
     * @return lampada mais gastadora
     */
    public Lampada maisGastadora() {
        return lampadas.stream().max((l1, l2) -> Double.compare(l1.getConsumo(), l2.getConsumo())).orElse(null);
    }

    /**
     * @brief Método que compara duas casas inteligentes
     * @param o
     * @return true se forem iguais, false caso contrário
     */
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || this.getClass() != o.getClass()) return false;
        CasaInteligente ci = (CasaInteligente) o;
        return this.lampadas.equals(ci.getLampadas());
    }

    /**
     * @brief Método que devolve todas as lampadas em modo eco
     * @return lampadas em modo eco
     */
    public Set<Lampada> lampadasEmModoEco(){
        return lampadas.stream().filter(Lampada::getEstado).collect(Collectors.toSet());
    }

    /**
     * @brief Método que reseta o consumo de todas as lampadas
     */
    public void reset() {
        lampadas.forEach(Lampada::lampOFF);
    }

    /**
     * @brief Método que devolve as 3 lampadas mais económicas
     * @return 3 lampadas mais económicas
     */
    public Set<Lampada> podiumEconomia(){
        return lampadas.stream().sorted((l1, l2) -> Double.compare(l1.getConsumo(), l2.getConsumo())).limit(3).collect(Collectors.toSet());
    }
}
