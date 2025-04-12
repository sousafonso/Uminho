import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class CarRental {
    private Map<String, Carro> carros;

    public CarRental(){
        this.carros = new HashMap<>();
    }

    public CarRental(Map<String, Carro> carros){
        this.carros = new HashMap<>(carros);
    }
    
    public boolean existeCarro(String cod){
        return carros.get(cod) != null;
    }

    public int quantos(){
        return carros.size();
    }

    public int quantos(String marca){
        int count = 0;
        for (Carro carro : carros.values()) {
            if (carro.getMarca().equals(marca)) {
                count++;
            }
        }
        return count;
    }
    
    public Carro getCarro(String cod) {
        return carros.get(cod);
    }

    public void adiciona(Carro v){
        carros.put(v.getMatricula(), v);
    }

    public List<Carro> getCarros(){
        return List.copyOf(carros.values());
    }

    public void adiciona(Set<Carro> vs){
        for (Carro carro : vs) {
            carros.put(carro.getMatricula(), carro);
        }
    }

    public void registarViagem(String codCarro, int numKms){
        Carro carro = carros.get(codCarro);
        if (carro != null) {
            carro.setKmPercorridos(carro.getKmPercorridos() + numKms);
            // Poderia atualizar a autonomia conforme a lógica da viagem
        } else {
            System.out.println("Carro não encontrado.");
        }
    }

    public void atestarCarro(String codCarro){
        Carro carro = carros.get(codCarro);
        if (carro != null) {
            if (carro instanceof CarroCombustao) {
                CarroCombustao cc = (CarroCombustao) carro;
                carro.setAutonomia(cc.getTamanho() * cc.getConsumo());
            } else if (carro instanceof CarroEletrico) {
                CarroEletrico ce = (CarroEletrico) carro;
                carro.setAutonomia(ce.getTamanho() * ce.getConsumo());
            } else {
                System.out.println("Tipo de carro não identificado.");
            }
        } else {
            System.out.println("Carro não encontrado.");
        }
    }

    // Calcula o custo real por km do carro acrescido de 15%
    private double custoRealPorKm(Carro carro) {
        double custoBase = 0;
        if (carro instanceof CarroCombustao) {
            CarroCombustao cc = (CarroCombustao) carro;
            custoBase = (cc.getConsumo() / 100.0) * cc.getPreco();
        } else if (carro instanceof CarroEletrico) {
            CarroEletrico ce = (CarroEletrico) carro;
            custoBase = (ce.getConsumo() / 100.0) * ce.getPreco();
        } else {
            // Caso genérico (assumindo que o campo consumo representa o custo base por km)
            custoBase = carro.getConsumo();
        }
        return custoBase * 1.15;
    }

    public Carro obterCarroMaisEconomico(){
        Carro carroMaisEconomico = null;
        double menorCusto = Double.MAX_VALUE;

        for (Carro carro : carros.values()) {
            double custo = custoRealPorKm(carro);
            if (custo < menorCusto) {
                menorCusto = custo;
                carroMaisEconomico = carro;
            }
        }

        return carroMaisEconomico;
    }

    public double obterMediaCustoPorKm(){
        double soma = 0;

        for (Carro carro : carros.values()) {
            soma += custoRealPorKm(carro);
        }

        return carros.size() > 0 ? soma / carros.size() : 0;
    }
}