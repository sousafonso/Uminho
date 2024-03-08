public class Encomenda {
    private String nomeCliente;

    private int nif;

    private String morada;

    private int numEncomenda;

    private String data;

    private LinhaEncomenda[] linhas;

    private Int referencia;

    private double precoSemImposto;

    private double precoComImposto;

    private double imposto;

    private double desconto;

    public Encomenda(){
        this.nomeCliente = "";
        this.nif = 0;
        this.morada = "";
        this.numEncomenda = 0;
        this.data = "";
        this.linhas = new LinhaEncomenda[10];
        this.desconto = 0;
        this.imposto = 0;
        this.precoComImposto = 0;
        this.precoSemImposto = 0;
        this.referencia = 0;
    }

    public Encomenda(String nomeCliente, int nif, String morada, int numEncomenda, String data, LinhaEncomenda[] linhas, double desconto, double imposto, double precoComImposto, double precoSemImposto, int referencia){
        this.nomeCliente = nomeCliente;
        this.nif = nif;
        this.morada = morada;
        this.numEncomenda = numEncomenda;
        this.data = data;
        this.linhas = linhas;
        this.desconto = 0;
        this.imposto = 0;
        this.precoComImposto = 0;
        this.precoSemImposto = 0;
        this.referencia = 0;
    }

    public Encomenda(Encomenda umaEncomenda){
        this.nomeCliente = umaEncomenda.getNomeCliente();
        this.nif = umaEncomenda.getNif();
        this.morada = umaEncomenda.getMorada();
        this.numEncomenda = umaEncomenda.getNumEncomenda();
        this.data = umaEncomenda.getData();
        this.linhas = umaEncomenda.getLinhas();
        this.desconto = umaEncomenda.getDesconto();
        this.imposto = umaEncomenda.getImposto();
        this.precoComImposto = umaEncomenda.getPrecoComImposto();
        this.precoSemImposto = umaEncomenda.getPrecoSemImposto();
        this.referencia = umaEncomenda.getReferencia();
    }

    public String getNomeCliente(){
        return this.nomeCliente;
    }

    public int getNif(){
        return this.nif;
    }

    public String getMorada(){
        return this.morada;
    }

    public int getNumEncomenda(){
        return this.numEncomenda;
    }

    public String getData(){
        return this.data;
    }

    public LinhaEncomenda[] getLinhas(){
        return this.linhas;
    }

    public double getPrecoSemImposto(){
        return this.precoSemImposto;
    }

    public double getPrecoComImposto(){
        return this.precoComImposto;
    }

    public double getImposto(){
        return this.imposto;
    }

    public double getDesconto(){
        return this.desconto;
    }

    public int getReferencia(){
        return this.referencia;
    }

    public void setNomeCliente(String nomeCliente){
        this.nomeCliente = nomeCliente;
    }

    public void setNif(int nif){
        this.nif = nif;
    }

    public void setMorada(String morada){
        this.morada = morada;
    }

    public void setNumEncomenda(int numEncomenda){
        this.numEncomenda = numEncomenda;
    }

    public void setData(String data){
        this.data = data;
    }

    public void setLinhas(LinhaEncomenda[] linhas){
        this.linhas = linhas;
    }

    public void setPrecoSemImposto(double precoSemImposto){
        this.precoSemImposto = precoSemImposto;
    }

    public void setPrecoComImposto(double precoComImposto){
        this.precoComImposto = precoComImposto;
    }

    public void setImposto(double imposto){
        this.imposto = imposto;
    }

    public void setDesconto(double desconto){
        this.desconto = desconto;
    }

    public void setReferencia(int referencia){
        this.referencia = referencia;
    }

    // Determina o valor da venda já considerados os impostos e os descontos
    public double calculaValorLinhaEnc(){
        double total = 0;
        for(LinhaEncomenda linha : this.linhas){
            total += linha.calculaValorLinhaEnc();
        }
        return total;
    }

    // Determina o valor do desconto em euros
    public double calculaValorDesconto(){
        return this.calculaValorLinhaEnc() * this.desconto;
    }

    public double calculaValorTotal(){
        return this.calculaValorLinhaEnc() - this.calculaValorDesconto() + this.calculaValorIva();
    }

    public int numeroTotalProdutos(){
        int total = 0;
        for(LinhaEncomenda linha : this.linhas){
            total += linha.getQuantidade();
        }
        return total;
    }

    public boolean existeProdutoEncomenda(String refProduto){
        for(LinhaEncomenda linha : this.linhas){
            if(linha.getReferencia().equals(refProduto)){
                return true;
            }
        }
        return false;
    }

    public void adicionaLinha(LinhaEncomenda linha){
        for(int i = 0; i < this.linhas.length; i++){
            if(this.linhas[i] == null){
                this.linhas[i] = linha;
                break;
            }
        }
    }

    public void removeProduto(String codProd){
        for(int i = 0; i < this.linhas.length; i++){
            if(this.linhas[i].getReferencia().equals(codProd)){
                this.linhas[i] = null;
                break;
            }
        }
    }
}