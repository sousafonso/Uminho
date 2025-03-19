import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Encomenda {
    private String nomeCliente;
    private String numeroFiscal;
    private String morada;
    private String numeroEncomenda;
    private LocalDate dataEncomenda;
    private List<LinhaEncomenda> linhas;  

    // Construtor parametrizado
    public Encomenda(String nomeCliente, String numeroFiscal, String morada, String numeroEncomenda, LocalDate dataEncomenda) {
        this.nomeCliente = nomeCliente;
        this.numeroFiscal = numeroFiscal;
        this.morada = morada;
        this.numeroEncomenda = numeroEncomenda;
        this.dataEncomenda = dataEncomenda;
        this.linhas = new ArrayList<>();
    }

    // Métodos de acesso e alteração (getters e setters)
    public String getNomeCliente() { return nomeCliente; }
    public void setNomeCliente(String nomeCliente) { this.nomeCliente = nomeCliente; }

    public String getNumeroFiscal() { return numeroFiscal; }
    public void setNumeroFiscal(String numeroFiscal) { this.numeroFiscal = numeroFiscal; }

    public String getMorada() { return morada; }
    public void setMorada(String morada) { this.morada = morada; }

    public String getNumeroEncomenda() { return numeroEncomenda; }
    public void setNumeroEncomenda(String numeroEncomenda) { this.numeroEncomenda = numeroEncomenda; }

    public LocalDate getDataEncomenda() { return dataEncomenda; }
    public void setDataEncomenda(LocalDate dataEncomenda) { this.dataEncomenda = dataEncomenda; }

    public List<LinhaEncomenda> getLinhas() { return linhas; }  
    public void setLinhas(List<LinhaEncomenda> linhas) { this.linhas = linhas; }  

    /**
     * Método que calcula o valor total da encomenda
     * @return valor total da encomenda com impostos e descontos aplicados
     */
    public double calculaValorTotal() {
        double total = 0.0;
        for (LinhaEncomenda linha : linhas) {
            total += linha.calculaValorLinhaEnc();
        }
        return total;
    }

    /**
     * Método que calcula o valor total dos descontos
     * @return valor total dos descontos aplicados na encomenda
     */
    public double calculaValorDesconto() {
        double totalDesconto = 0.0;
        for (LinhaEncomenda linha : linhas) {
            totalDesconto += linha.calculaValorDesconto();
        }
        return totalDesconto;
    }

    /**
     * Método que calcula o número total de produtos
     * @return soma das quantidades de todos os produtos
     */
    public int numeroTotalProdutos() {
        int totalProdutos = 0;
        for (LinhaEncomenda linha : linhas) {
            totalProdutos += linha.getQuantidade();
        }
        return totalProdutos;
    }

    /**
     * Método que verifica se um produto existe na encomenda através da referência
     * @param refProduto referência do produto a verificar
     * @return true se o produto existir na encomenda, false caso contrário
     */
    public boolean existeProdutoEncomenda(String refProduto) {
        for (LinhaEncomenda linha : linhas) {
            if (linha.getReferencia().equals(refProduto)) {  
                return true;
            }
        }
        return false;
    }

    /**
     * Adiciona uma linha de encomenda à encomenda
     * @param linha linha de encomenda a adicionar
     */
    public void adicionaLinha(LinhaEncomenda linha) {
        linhas.add(linha);
    }

    /**
     * Remove uma linha de encomenda com base na referência do produto
     * @param codProd referência do produto a remover
     */
    public void removeProduto(String codProd) {
        linhas.removeIf(linha -> linha.getReferencia().equals(codProd));  
    }

    public boolean equals (Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || this.getClass() != o.getClass()) {
            return false;
        }
        Encomenda e = (Encomenda) o;
        return this.nomeCliente.equals(e.getNomeCliente()) && this.numeroFiscal.equals(e.getNumeroFiscal()) && this.morada.equals(e.getMorada()) && this.numeroEncomenda.equals(e.getNumeroEncomenda()) && this.dataEncomenda.equals(e.getDataEncomenda()) && this.linhas.equals(e.getLinhas());
    }

    public static void main(String[] args) {
        // Criando uma encomenda de exemplo
        Encomenda encomenda = new Encomenda("João Silva", "123456789", "Rua A, 123", "ENC001", LocalDate.now());

        // Adicionando linhas de encomenda
        LinhaEncomenda linha1 = new LinhaEncomenda("P001", "Produto 1", 50.0, 2, 23.0, 10.0);
        LinhaEncomenda linha2 = new LinhaEncomenda("P002", "Produto 2", 30.0, 5, 23.0, 5.0);
        encomenda.adicionaLinha(linha1);
        encomenda.adicionaLinha(linha2);

        // Testando os métodos
        System.out.println("Valor total da encomenda: " + encomenda.calculaValorTotal());
        System.out.println("Valor total dos descontos: " + encomenda.calculaValorDesconto());
        System.out.println("Número total de produtos: " + encomenda.numeroTotalProdutos());
        System.out.println("Produto P001 existe na encomenda? " + encomenda.existeProdutoEncomenda("P001"));
        
        encomenda.removeProduto("P001");
        System.out.println("Produto P001 existe na encomenda após remoção? " + encomenda.existeProdutoEncomenda("P001"));
    }
}