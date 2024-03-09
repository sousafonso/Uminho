

public class Carro {
    private String marca;
    private String modelo;
    private int ano;
    private Float consumo; // consumo em litros a uma velocidade de 100km/h
    private int quilometros;
    private Float mediaConsumo; // media de consumo desde o ínicio
    private int quilometrosUltimaViagem;
    private Float consumoUltimaViagem;
    private Float regeneracao; // capacidade de regeneração de energia (abate ao consumo) quando se trava durante 1 km (o cálculo é também linear)

    public Carro(String marca, String modelo, int ano, Float consumo, int quilometros, Float mediaConsumo, int quilometrosUltimaViagem, Float consumoUltimaViagem, Float regeneracao){
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

    public void setAno(int ano){
        this.ano = ano;
    }

    public int getAno(){
        return this.ano;
    }

    public void setConsumo(Float consumo){
        this.consumo = consumo;
    }

    public Float getConsumo(){
        return this.consumo;
    }

    public void setQuilometros(int quilometros){
        this.quilometros = quilometros;
    }

    public int getQuilometros(){
        return this.quilometros;
    }

    public void setMediaConsumo(Float mediaConsumo){
        this.mediaConsumo = mediaConsumo;
    }

    public Float getMediaConsumo(){
        return this.mediaConsumo;
    }

    public void setQuilometrosUltimaViagem(int quilometrosUltimaViagem){
        this.quilometrosUltimaViagem = quilometrosUltimaViagem;
    }

    public int getQuilometrosUltimaViagem(){
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
        consumoUltimaViagem = 0.0f; // Fix: Convert the integer value to float
        System.out.println("Carro ligado");
    }

    public void desligaCarro(){
        System.out.println("Carro desligado");
    }

    public void resetUltimaViagem(){
        quilometrosUltimaViagem = 0;
        consumoUltimaViagem = 0.0f; // Fix: Convert the integer value to float
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