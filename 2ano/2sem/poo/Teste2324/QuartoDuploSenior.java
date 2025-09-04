import java.io.Serializable;

public class QuartoDuploSenior extends Quarto implements Serializable {
    private double precoBase;

    public QuartoDuploSenior(String numeroQuarto, double precoBase) {
        super(numeroQuarto);
        this.precoBase = precoBase;
    }

    @Override
    public double precoPorDia() {
        return precoBase;
    }
}