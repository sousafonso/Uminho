public class LinhaEncomenda{
    private String referencia;
    private String descricao;
    private int precoBefore;
    private int quantidade;
    private int imposto;
    private int desconto;

    public String getReferencia (){
        return this.referencia;
    }

    public String getDescricao (){
        return this.descricao;
    }

    public int getPrecoBefore (){
        return this.precoBefore;
    }

    public int getQuantidade (){
        return this.quantidade;
    }

    public int getImposto (){
        return this.imposto;
    }

    public int getDesconto (){
        return this.desconto;
    }

    public void setReferencia (String referencia){
        this.referencia = referencia;
    }

    public void setDescricao (String descricao){
        this.descricao = descricao;
    }

    public void setPrecoBefore (int precoBefore){
        this.precoBefore = precoBefore;
    }

    public void setQuantidade (int quantidade){
        this.quantidade = quantidade;
    }

    public void setImposto (int imposto){
        this.imposto = imposto;
    }

    public void setDesconto (int desconto){
        this.desconto = desconto;
    }

    public LinhaEncomenda (){
        this.referencia = "";
        this.descricao = "";
        this.precoBefore = 0;
        this.quantidade = 0;
        this.imposto = 0;
        this.desconto = 0;
    }

    public LinhaEncomenda (String referencia, String descricao, int precoBefore, int quantidade, int imposto, int desconto){
        this.referencia = referencia;
        this.descricao = descricao;
        this.precoBefore = precoBefore;
        this.quantidade = quantidade;
        this.imposto = imposto;
        this.desconto = desconto;
    }

    public LinhaEncomenda (LinhaEncomenda le){
        this.referencia = le.getReferencia();
        this.descricao = le.getDescricao();
        this.precoBefore = le.getPrecoBefore();
        this.quantidade = le.getQuantidade();
        this.imposto = le.getImposto();
        this.desconto = le.getDesconto();
    }

    public double calculaValorLinhaEnc(){
        double precoComDesconto = precoBefore * (1 - (desconto / 100));
        double precoComImposto = precoComDesconto * (1 + (imposto / 100));
        return quantidade * precoComImposto;
    }

    public double calculaValorDesconto(){
        return quantidade * precoBefore * (desconto / 100);
    }

    public static void main(String[] args) {
        LinhaDeEncomenda linha = new LinhaDeEncomenda("P1234", "Produto Teste", 100.0, 10, 23.0, 10.0);

        // Testando os métodos
        System.out.println("Valor da linha de encomenda: " + linha.calculaValorLinhaEnc());
        System.out.println("Valor do desconto: " + linha.calculaValorDesconto());
    }
}