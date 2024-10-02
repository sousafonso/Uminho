public class Circulo {
    private Ponto p = new Ponto();
    private double raio;

    public double getX (){
        return this.p.getX();
    }
    public double getY (){
        return this.p.getY();
    }

    public double getRaio(){
        return this.raio;
    }

    public void setX(double x){
        this.x=x;
    }

    public void setY(double y){
        this.y=y;
    }

    public void setRaio(double raio){
        this.raio = raio;
    }

    public void alteraCentro(double x, double y){
        p.setX(x);
        p.setY(y);
    }

    public double calculaArea(){
        return 2*pi*pow(getRaio(),2);
    }

    public double calculaPerimetro()
}