import java.io.Serializable;

public abstract class Quarto implements Serializable {
    private String numeroQuarto;
    
    public Quarto(String numeroQuarto) {
        this.numeroQuarto = numeroQuarto;
    }

    public String getNumeroQuarto() {
        return numeroQuarto;
    }
    public void setNumeroQuarto(String numeroQuarto) {
        this.numeroQuarto = numeroQuarto;
    }

    public abstract double precoPorDia(); 
}