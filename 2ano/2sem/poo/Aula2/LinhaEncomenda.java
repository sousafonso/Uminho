public class LinhaEncomenda {
    private String referencia;
    private String descricao;
    private double precoBefore;  
    private int quantidade;
    private double imposto;      
    private double desconto;     

    public String getReferencia() {
        return this.referencia;
    }

    public String getDescricao() {
        return this.descricao;
    }

    public double getPrecoBefore() {  
        return this.precoBefore;
    }

    public int getQuantidade() {
        return this.quantidade;
    }

    public double getImposto() {
        return this.imposto;
    }

    public double getDesconto() {  
        return this.desconto;
    }

    public void setReferencia(String referencia) {
        this.referencia = referencia;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public void setPrecoBefore(double precoBefore) {  
        this.precoBefore = precoBefore;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public void setImposto(double imposto) {  
        this.imposto = imposto;
    }

    public void setDesconto(double desconto) {  
        this.desconto = desconto;
    }

    public LinhaEncomenda() {
        this.referencia = "";
        this.descricao = "";
        this.precoBefore = 0.0;  
        this.quantidade = 0;
        this.imposto = 0.0;
        this.desconto = 0.0;     
    }

    public LinhaEncomenda(String referencia, String descricao, double precoBefore, int quantidade, double imposto, double desconto) {
        this.referencia = referencia;
        this.descricao = descricao;
        this.precoBefore = precoBefore;
        this.quantidade = quantidade;
        this.imposto = imposto;
        this.desconto = desconto;
    }

    public LinhaEncomenda(LinhaEncomenda le) {
        this.referencia = le.getReferencia();
        this.descricao = le.getDescricao();
        this.precoBefore = le.getPrecoBefore();
        this.quantidade = le.getQuantidade();
        this.imposto = le.getImposto();
        this.desconto = le.getDesconto();
    }

    public double calculaValorLinhaEnc() {
        double precoComDesconto = precoBefore * (1 - (desconto / 100.0));
        double precoComImposto = precoComDesconto * (1 + (imposto / 100.0));
        return quantidade * precoComImposto;
    }

    public double calculaValorDesconto() {
        return quantidade * precoBefore * (desconto / 100.0);
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if ((o == null) || (this.getClass() != o.getClass())) {
            return false;
        }
        LinhaEncomenda le = (LinhaEncomenda) o;
        return this.referencia.equals(le.getReferencia()) &&
               this.descricao.equals(le.getDescricao()) &&
               this.precoBefore == le.getPrecoBefore() &&
               this.quantidade == le.getQuantidade() &&
               this.imposto == le.getImposto() &&
               this.desconto == le.getDesconto();
    }

    public static void main(String[] args) {
        LinhaEncomenda linha = new LinhaEncomenda("P1234", "Produto Teste", 100.0, 10, 23.0, 10.0);

        // Testando os métodos
        System.out.println("Valor da linha de encomenda: " + linha.calculaValorLinhaEnc());
        System.out.println("Valor do desconto: " + linha.calculaValorDesconto());
    }
}