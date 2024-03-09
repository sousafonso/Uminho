import java.lang.Math;

public class CirculoPonto {
    private int raio;
    private Ponto centro;

    public CirculoPonto(){
        this.raio = 0;
        this.centro = new Ponto();
    }

    public CirculoPonto(int raio, Ponto centro){
        this.raio = raio;
        this.centro = centro.clone();
    }

    public CirculoPonto(CirculoPonto umCirculo){
        this.raio = umCirculo.getRaio();
        this.centro = umCirculo.getCentro();
    }

    public int getRaio(){
        return this.raio;
    }

    public Ponto getCentro(){
        return this.centro.clone();
    }

    public void setRaio(int raio){
        this.raio = raio;
    }

    public void setCentro(Ponto centro){
        this.centro = centro.clone();
    }

    public void setX(int x){
        this.centro.setX(x);
    }

    public void setY(int y){
        this.centro.setY(y);
    }

    public int getX(){
        return centro.getX();
    }

    public int getY(){
        return centro.getY();
    }

    public void alteraCentro(int x, int y){
        this.centro.setX(x);
        this.centro.setY(y);
    }

    public double calculaArea(){
        return Math.PI * Math.pow(this.raio, 2);
    }

    public double calculaPerimetro(){
        return 2 * Math.PI * this.raio;
    }

    public String toString(){
        return "O circulo tem raio:" + this.getRaio() + " e centro:" + this.getCentro();
    }

    public boolean equals(Object o){
        if (this == o)
            return true;
        if ((o == null) || (this.getClass() != o.getClass()))
            return false;
        CirculoPonto c = (CirculoPonto) o;
        return (this.raio == c.getRaio() && this.centro.equals(c.getCentro()));
    }
}
