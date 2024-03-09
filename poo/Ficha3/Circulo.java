
import java.lang.Math;

// Criação da classe Circulo

public class Circulo{
    private int x;

    private int y;

    private int raio;

    public Circulo(){
        this.x = 0;
        this.y = 0;
        this.raio = 0;
    }

    public Circulo(int x, int y, int raio){
        this.x = x;
        this.y = y;
        this.raio = raio;
    }

    // COPIA DE UM OBJETO (DAS VARIÁVEIS DE INSTÂNCIA)
    public Circulo (Circulo umCirculo){
        this.x = umCirculo.getX();
        this.y = umCirculo.getY();
        this.raio = umCirculo.getRaio();
    }

    public int getX(){
        return this.x;
    }

    public int getY(){
        return this.y;
    }

    public int getRaio(){
        return this.raio;
    }

    public String toString(){
        return "O circulo tem x:" + this.getX() + "y:" + this.getY() + "e raio:" + this.getRaio();
    }

    public void setX(int x){
        this.x = x;
    }

    public void setY(int y){
        this.y = y;
    }

    public void setRaio(int raio){
        this.raio = raio;
    }

    public void alteraCentro(int x, int y){
        setX(x);
        setY(y);
    }

    public double calculaArea(){
        return Math.PI * Math.pow(this.raio, 2);
    }

    public double calculaPerimetro(){
        return 2 * Math.PI * this.raio;
    }

    // o objetivo é comparar dois circulos
    public boolean equals(Object o) {
        if (this == o) return true; // se o objeto for igual a si mesmo retorna verdadeiro
        if (!(o instanceof Circulo)) return false; // se o objeto não for do tipo Circulo retorna falso
        Circulo umCirculo = (Circulo) o;
        return this.x == umCirculo.getX() && this.y == umCirculo.getY() && this.raio == umCirculo.getRaio();
        // return getX() == umCirculo.getX() && getY() == umCirculo.getY() && getRaio() == umCirculo.getRaio();
    }
}