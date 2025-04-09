public class Carro {
    private String matricula;
    private String modelo;
    private String marca;
    private int ano;
    private int velocidade; //velocidade média por km
    private float consumo; //consumo por km a uma velocidade de 100 km/h (serve de referência para cálculos lineares do consumo)
    private float autonomia; //autonomia em km
    private int kmPercorridos; //km percorridos

    public Carro (Carro carro){
        this.matricula = carro.getMatricula();
        this.modelo = carro.getModelo();
        this.marca = carro.getMarca();
        this.ano = carro.getAno();
        this.velocidade = carro.getVelocidade();
        this.consumo = carro.getConsumo();
        this.autonomia = carro.getAutonomia();
        this.kmPercorridos = carro.getKmPercorridos();
    }

    public Carro (String matricula, String modelo, String marca, int ano, int velocidade, int kmPercorridos, float consumo, float autonomia){
        this.matricula = matricula;
        this.modelo = modelo;
        this.marca = marca;
        this.ano = ano;
        this.velocidade = velocidade;
        this.kmPercorridos = kmPercorridos;
        this.consumo = consumo;
        this.autonomia = autonomia;
    }

    public Carro (){
        this.matricula = "";
        this.modelo = "";
        this.marca = "";
        this.ano = 0;
        this.velocidade = 0;
        this.consumo = 0;
        this.autonomia = 0;
        this.kmPercorridos = 0;
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public int getVelocidade() {
        return velocidade;
    }

    public void setVelocidade(int velocidade) {
        this.velocidade = velocidade;
    }

    public float getConsumo() {
        return consumo;
    }

    public void setConsumo(float consumo) {
        this.consumo = consumo;
    }

    public float getAutonomia() {
        return autonomia;
    }

    public void setAutonomia(float autonomia) {
        this.autonomia = autonomia;
    }

    public int getKmPercorridos() {
        return kmPercorridos;
    }

    public void setKmPercorridos(int kmPercorridos) {
        this.kmPercorridos = kmPercorridos;
    }



}