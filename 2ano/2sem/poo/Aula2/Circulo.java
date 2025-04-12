public class Circulo {
    private Ponto p = new Ponto();
    private double raio;

    public Circulo(){
        this.p.setX(0);
        this.p.setY(0);
        this.raio = 1;
    }
    public Circulo(int x, int y, double raio){
        this.p.setX(x);
        this.p.setY(y);
        this.raio = raio;
    }

    public double getRaio(){
        return this.raio;
    }

    public void setRaio(double raio){
        this.raio = raio;
    }

    public void alteraCentro(double x, double y){
        this.p.setX(x);
        this.p.setY(y);
    }

    public double calculaArea(){
        return Math.PI * Math.pow(raio, 2);
    }

    public double calculaPerimetro(){
        return 2 * Math.PI * raio;
    }
}