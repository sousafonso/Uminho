public class CarroEletrico extends Carro {
    private int tamanho; //tamanho em kWh da bateria;
    private float consumokWh; // consumo em litros aos 100km
    private float precokW; 

    public CarroEletrico (){
        this.tamanho = 0;
        this.consumokWh = 0;
        this.precokW = 0;
    }

    public CarroEletrico (int tamanho, float consumokWh, float precokW, String matricula, String modelo, String marca, int ano, int velocidade, int kmPercorridos, float consumo, float autonomia){
        super(matricula, modelo, marca, ano, velocidade, kmPercorridos, consumo, autonomia);
        this.tamanho = tamanho;
        this.consumokWh = consumokWh;
        this.precokW = precokW;
    }

    public CarroEletrico (CarroEletrico carroEletrico){
        super(carroEletrico);
        this.tamanho = carroEletrico.getTamanho();
        this.consumokWh = carroEletrico.getConsumo();
        this.precokW = carroEletrico.getPreco();
    }

    public int getTamanho() {
        return tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public float getConsumo() {
        return consumokWh;
    }

    public void setConsumo(float consumokWh) {
        this.consumokWh = consumokWh;
    }

    public float getPreco() {
        return precokW;
    }

    public void setPreco(float precokW) {
        this.precokW = precokW;
    }
}