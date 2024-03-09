public class LinhaEncomenda {
    private String referenciaProduto;
    private String descricaoProduto;
    private double precoAntesImpostos;
    private int quantidadeEncomendada;
    private double taxaImposto; // representado como uma porcentagem, por exemplo, 23 para 23%
    private double percentagemDesconto; // representado como uma porcentagem, por exemplo, 10 para 10%

    // Construtor
    public LinhaEncomenda(String referenciaProduto, String descricaoProduto, double precoAntesImpostos,
                            int quantidadeEncomendada, double taxaImposto, double percentagemDesconto) {
        this.referenciaProduto = referenciaProduto;
        this.descricaoProduto = descricaoProduto;
        this.precoAntesImpostos = precoAntesImpostos;
        this.quantidadeEncomendada = quantidadeEncomendada;
        this.taxaImposto = taxaImposto;
        this.percentagemDesconto = percentagemDesconto;
    }

    // Métodos de acesso e alteração (getters e setters)
    public String getReferenciaProduto() {
        return referenciaProduto;
    }

    public void setReferenciaProduto(String referenciaProduto) {
        this.referenciaProduto = referenciaProduto;
    }

    public String getDescricaoProduto() {
        return descricaoProduto;
    }

    public void setDescricaoProduto(String descricaoProduto) {
        this.descricaoProduto = descricaoProduto;
    }

    public double getPrecoAntesImpostos() {
        return precoAntesImpostos;
    }

    public void setPrecoAntesImpostos(double precoAntesImpostos) {
        this.precoAntesImpostos = precoAntesImpostos;
    }

    public int getQuantidadeEncomendada() {
        return quantidadeEncomendada;
    }

    public void setQuantidadeEncomendada(int quantidadeEncomendada) {
        this.quantidadeEncomendada = quantidadeEncomendada;
    }

    public double getTaxaImposto() {
        return taxaImposto;
    }

    public void setTaxaImposto(double taxaImposto) {
        this.taxaImposto = taxaImposto;
    }

    public double getPercentagemDesconto() {
        return percentagemDesconto;
    }

    public void setPercentagemDesconto(double percentagemDesconto) {
        this.percentagemDesconto = percentagemDesconto;
    }

    // Método que determina o valor da venda já considerando os impostos e os descontos
    public double calculaValorLinhaEnc() {
        double precoComDesconto = precoAntesImpostos * (1 - percentagemDesconto / 100);
        double precoComImpostos = precoComDesconto * (1 + taxaImposto / 100);
        return precoComImpostos * quantidadeEncomendada;
    }

    // Método que determina o valor numérico (em euros) do desconto
    public double calculaValorDesconto() {
        return precoAntesImpostos * quantidadeEncomendada * (percentagemDesconto / 100);
    }
}
