public class CarroCombustao extends Carro {
    private int tamanho; //tamanho em litros do depósito;
    private float consumoLitros; // consumo em litros aos 100km
    private float precoLitro; 

    public CarroCombustao (){
        this.tamanho = 0;
        this.consumoLitros = 0;
        this.precoLitro = 0;
    }

    public CarroCombustao (int tamanho, float consumoLitros, float precoLitro, String matricula, String modelo, String marca, int ano, int velocidade, int kmPercorridos, float consumo, float autonomia){
        super(matricula, modelo, marca, ano, velocidade, kmPercorridos, consumo, autonomia);
        this.tamanho = tamanho;
        this.consumoLitros = consumoLitros;
        this.precoLitro = precoLitro;
    }

    public CarroCombustao (CarroCombustao carroCombustao){
        super(carroCombustao);
        this.tamanho = carroCombustao.getTamanho();
        this.consumoLitros = carroCombustao.getConsumo();
        this.precoLitro = carroCombustao.getPreco();
    }

    public int getTamanho() {
        return tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public float getConsumo() {
        return consumoLitros;
    }

    public void setConsumo(float consumoLitros) {
        this.consumoLitros = consumoLitros;
    }

    public float getPreco() {
        return precoLitro;
    }

    public void setPreco(float precoLitro) {
        this.precoLitro = precoLitro;
    }
}