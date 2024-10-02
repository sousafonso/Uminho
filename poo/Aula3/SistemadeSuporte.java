package Aula3;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class SistemadeSuporte {
    private List<PedidodeSuporte> pedidos;

    /**
     * Construtor vazio
     */
    public SistemadeSuporte(){
        pedidos = new ArrayList<>();
    }

    /**
     * Construtor com parâmetros
     */
    public SistemadeSuporte(List<PedidodeSuporte> pedidos){
        this.pedidos = new ArrayList<>(pedidos);
    }

    /**
     * Método que insere um pedido de suporte
     */
    public void inserePedido(PedidodeSuporte p){
        pedidos.add(p);
    }

    /**
     * Método que procura um pedido de suporte
     * @param user
     * @param data
     * @return
     */
    public PedidodeSuporte procuraPedido(String user, LocalDateTime data){
        return pedidos.stream().filter(p->p.getCliente().equals(user)
        && p.getTi().equals(data)).findFirst()
        .orElse(null);
    }

    /**
     * Método que resolve um pedido de suporte
     * @param pedido
     * @param tecnico
     * @param info
     */
    public void resolvePedido(PedidodeSuporte pedido, String tecnico, String info){
        pedido.setTrabalhador(tecnico);
        pedido.setInformacao(info);
        pedido.setTf(LocalDateTime.now());
    }

    /**
     * Método que devolve a lista de pedidos resolvidos
     * @return
     */
    public List<PedidodeSuporte> resolvidos(){
        return pedidos.stream().filter(p->p.getTf() != null).collect(Collector.toList());
    }

    /**
     * Método que devolve o colaborador que resolveu mais pedidos
     * @return
     */
    public String colaboradorTop(){
        return pedidos.stream()
                        .filter(p -> p.getTf() != null)
                        .collect(Collectors.groupingBy(PedidoDeSuporte::getTrabalhador, Collectors.counting()))
                        /**
                         * Agrupa os pedidos por técnico (usando o método getTrabalhador do pedido) 
                         * e conta quantos pedidos cada técnico resolveu. O resultado é um Map<String, Long> 
                         * onde a chave é o nome do técnico e o valor é o número de pedidos resolvidos por 
                         * esse técnico.
                         */
                        .entrySet().stream() /**
                        Converte o conjunto de entradas do mapa (Map.Entry<String, Long>) 
                        em um stream para processamento adicional. */
                        .max(Map.Entry.comparingByValue())
                        .map(Map.Entry::getKey)
                        .orElse(null);
    }

    /**
     * Método que devolve a lista de pedidos resolvidos num determinado intervalo
     * @param inicio
     * @param fim
     * @return
     */
    public List<PedidodeSuporte> resolvidos(LocalDateTime inicio, LocalDateTime fim){
        return pedidos.stream().filter(p-> !p.getTf().isAfter(inicio) && !p.getTf().isBefore(fim))
        .collect(Collectors.toList());
    }

    /**
     * Método que devolve o tempo médio de resolução dos pedidos
     * @return
     */
    public double tempoMedioResolucao(){
        return pedidos.stream()
                .filter(p -> p.getTf() != null)
                .mapToLong(p -> Duration.between(p.getTi(), p.getTf()).toMinutes())
                .average()
                .orElse(0);
    }

    /**
     * Método que devolve o tempo médio de resolução dos pedidos num determinado intervalo
     * @param inicio
     * @param fim
     * @return
     */
    public double tempoMedioResolucao(LocalDateTime inicio, LocalDateTime fim){
        return pedidos.stream()
                .filter(p -> p.getTf() != null && 
                             !p.getTf().isBefore(inicio) && 
                             !p.getTf().isAfter(fim))
                .mapToLong(p -> Duration.between(p.getTi(), p.getTf()).toMinutes())
                .average()
                .orElse(0);
    }

    /**
     * Método que devolve o pedido de suporte que demorou mais tempo a ser resolvido
     * @return
     */
    public PedidoDeSuporte pedidoMaisLongo() {
        return pedidos.stream()
                .filter(p -> p.getTf() != null)
                .max(Comparator.comparingLong(p -> Duration.between(p.getTi(), p.getTf()).toMinutes()))
                .orElse(null);
    }

    /**
     * Método que devolve o pedido de suporte que demorou mais tempo a ser resolvido num determinado intervalo
     * @param inicio
     * @param fim
     * @return
     */
    public PedidoDeSuporte pedidoMaisLongo(LocalDateTime inicio, LocalDateTime fim) {
        return pedidos.stream()
                .filter(p -> p.getTf() != null && 
                             !p.getTf().isBefore(inicio) && 
                             !p.getTf().isAfter(fim))
                .max(Comparator.comparingLong(p -> Duration.between(p.getTi(), p.getTf()).toMinutes()))
                .orElse(null);
    }

    /**
     * Método que devolve o pedido de suporte que demorou menos tempo a ser resolvido
     * @return
     */
    public PedidoDeSuporte pedidoMaisCurto() {
        return pedidos.stream()
                .filter(p -> p.getTf() != null)
                .min(Comparator.comparingLong(p -> Duration.between(p.getTi(), p.getTf()).toMinutes()))
                .orElse(null);
    }

    /**
     * Método que devolve o pedido de suporte que demorou menos tempo a ser resolvido num determinado intervalo
     * @param inicio
     * @param fim
     * @return
     */
    public PedidoDeSuporte pedidoMaisCurto(LocalDateTime inicio, LocalDateTime fim) {
        return pedidos.stream()
                .filter(p -> p.getTf() != null && 
                             !p.getTf().isBefore(inicio) && 
                             !p.getTf().isAfter(fim))
                .min(Comparator.comparingLong(p -> Duration.between(p.getTi(), p.getTf()).toMinutes()))
                .orElse(null);
    }

    public static void main(String[] args) {
        SistemaDeSuporte sistema = new SistemaDeSuporte();
 
        // Adicionando pedidos de suporte
        PedidoDeSuporte p1 = new PedidoDeSuporte("user1", LocalDateTime.now().minusHours(5), "Assunto1", "Descrição1");
        PedidoDeSuporte p2 = new PedidoDeSuporte("user2", LocalDateTime.now().minusHours(3), "Assunto2", "Descrição2");
        PedidoDeSuporte p3 = new PedidoDeSuporte("user1", LocalDateTime.now().minusHours(2), "Assunto3", "Descrição3");

        sistema.inserePedido(p1);
        sistema.inserePedido(p2);
        sistema.inserePedido(p3);

        // Resolvido pedidos
        sistema.resolvePedido(p1, "tecnico1", "Resolvido com sucesso");
        sistema.resolvePedido(p2, "tecnico2", "Resolvido com sucesso");
        sistema.resolvePedido(p3, "tecnico1", "Resolvido com sucesso");

        // Testando métodos
        System.out.println("Pedido mais longo: " + sistema.pedidoMaisLongo().getAssunto());
        System.out.println("Pedido mais curto: " + sistema.pedidoMaisCurto().getAssunto());
        System.out.println("Tempo médio de resolução: " + sistema.tempoMedioResolucao() + " minutos");
        System.out.println("Colaborador top: " + sistema.colaboradorTop());
    }
}
