public class Carro {
    private String marca;
    private String modelo;
    private Int ano;
    private Float consumo; // consumo em litros a uma velocidade de 100km/h
    private Int quilometros;
    private Float mediaConsumo; // media de consumo desde o ínicio
    private Int quilometrosUltimaViagem;
    private Float consumoUltimaViagem;
    private Float regeneracao; // capacidade de regeneração de energia (abate ao consumo) quando se trava durante 1 km (o cálculo é também linear)

    public Carro(String marca, String modelo, Int ano, Float consumo, Int quilometros, Float mediaConsumo, Int quilometrosUltimaViagem, Float consumoUltimaViagem, Float regeneracao){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.consumo = consumo;
        this.quilometros = quilometros;
        this.mediaConsumo = mediaConsumo;
        this.quilometrosUltimaViagem = quilometrosUltimaViagem;
        this.consumoUltimaViagem = consumoUltimaViagem;
        this.regeneracao = regeneracao;
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public String getMarca(){
        return this.marca;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public String getModelo(){
        return this.modelo;
    }

    public void setAno(Int ano){
        this.ano = ano;
    }

    public Int getAno(){
        return this.ano;
    }

    public void setConsumo(Float consumo){
        this.consumo = consumo;
    }

    public Float getConsumo(){
        return this.consumo;
    }

    public void setQuilometros(Int quilometros){
        this.quilometros = quilometros;
    }

    public Int getQuilometros(){
        return this.quilometros;
    }

    public void setMediaConsumo(Float mediaConsumo){
        this.mediaConsumo = mediaConsumo;
    }

    public Float getMediaConsumo(){
        return this.mediaConsumo;
    }

    public void setQuilometrosUltimaViagem(Int quilometrosUltimaViagem){
        this.quilometrosUltimaViagem = quilometrosUltimaViagem;
    }

    public Int getQuilometrosUltimaViagem(){
        return this.quilometrosUltimaViagem;
    }

    public void setConsumoUltimaViagem(Float consumoUltimaViagem){
        this.consumoUltimaViagem = consumoUltimaViagem;
    }

    public Float getConsumoUltimaViagem(){
        return this.consumoUltimaViagem;
    }

    public void setRegeneracao(Float regeneracao){
        this.regeneracao = regeneracao;
    }

    public Float getRegeneracao(){
        return this.regeneracao;
    }

    public void ligaCarro(){
        quilometrosUltimaViagem = 0;
        consumoUltimaViagem = 0;
        System.out.println("Carro ligado");
    }

    public void desligaCarro(){
        System.out.println("Carro desligado");
    }

    public void resetUltimaViagem(){
        quilometrosUltimaViagem = 0;
        consumoUltimaViagem = 0;
    }

    public void avancaCarro(double metros, double velocidade){
        quilometros += metros;
        quilometrosUltimaViagem += metros;
        System.out.println("Carro avancou " + metros + " metros a " + velocidade + " km/h");
    }

    public void travaCarro(double metros){
        quilometros += metros;
        quilometrosUltimaViagem += metros;
        System.out.println("Carro travou " + metros + " metros");
    }
}