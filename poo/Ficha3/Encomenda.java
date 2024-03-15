import javax.xml.crypto.Data;

public class Encomenda {
    String nome;
    int nif;
    String morada = new String();
    LinhaEncomenda[] linhas = new LinhaEncomenda[10];
    Data data;
    int numero;

    Encomenda(String nome, int nif, String morada, LinhaEncomenda[] linhas, Data data, int numero) {
        this.nome = nome;
        this.nif = nif;
        this.morada = morada;
        this.linhas = linhas;
        this.data = data;
        this.numero = numero;
    }

    Encomenda(Encomenda e) {
        this.nome = e.getNome();
        this.nif = e.getNif();
        this.morada = e.getMorada();
        this.linhas = e.getLinhas();
        this.data = e.getData();
        this.numero = e.getNumero();
    }

    public String getNome() {
        return this.nome;
    }

    public int getNif() {
        return this.nif;
    }

    public String getMorada() {
        return this.morada;
    }

    public LinhaEncomenda[] getLinhas() {
        return this.linhas;
    }

    public Data getData() {
        return this.data;
    }

    public int getNumero() {
        return this.numero;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNif(int nif) {
        this.nif = nif;
    }

    public void setMorada(String morada) {
        this.morada = morada;
    }

    public void setLinhas(LinhaEncomenda[] linhas) {
        this.linhas = linhas;
    }

    public void setData(Data data) {
        this.data = data;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public double calculaValorTotal() {
        double total = 0;
        for (LinhaEncomenda linha : linhas) {
            total += linha.calculaValorLinhaEnc();
        }
        return total;
    }

    public double calculaValorDesconto() {
        double total = 0;
        for (LinhaEncomenda linha : linhas) {
            total += linha.calculaValorDesconto();
        }
        return total;
    }

    public int numeroTotalProdutos() {
        int total = 0;
        for (LinhaEncomenda linha : linhas) {
            total += linha.getQuantidadeEncomendada();
        }
        return total;
    }

    public boolean existeProdutoEncomenda(String refProduto) {
        for (LinhaEncomenda linha : linhas) {
            if (linha.getReferenciaProduto().equals(refProduto)) {
                return true;
            }
        }
        return false;
    }

    public void adicionaLinha(LinhaEncomenda linha) {
        for (int i = 0; i < linhas.length; i++) {
            if (linhas[i] == null) {
                linhas[i] = linha;
                break;
            }
        }
    }

    public void removeProduto(String codProd) {
        for (int i = 0; i < linhas.length; i++) {
            if (linhas[i].getReferenciaProduto().equals(codProd)) {
                linhas[i] = null;
                break;
            }
        }
    }

}
