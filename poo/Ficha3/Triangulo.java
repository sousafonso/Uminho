public class Triangulo{
    private int x1, x2, x3, y1, y2, y3;

    public Triangulo(int x1, int x2, int x3, int y1, int y2, int y3){
        this.x1 = x1;
        this.x2 = x2;
        this.x3 = x3;
        this.y1 = y1;
        this.y2 = y2;
        this.y3 = y3;
    }

    public void setX1(int x1){
        this.x1 = x1;
    }

    public int getX1(){
        return this.x1;
    }

    public void setX2(int x2){
        this.x2 = x2;
    }

    public int getX2(){
        return this.x2;
    }

    public void setX3(int x3){
        this.x3 = x3;
    }

    public int getX3(){
        return this.x3;
    }

    public void setY1(int y1){
        this.y1 = y1;
    }

    public int getY1(){
        return this.y1;
    }

    public void setY2(int y2){
        this.y2 = y2;
    }

    public int getY2(){
        return this.y2;
    }

    public void setY3(int y3){
        this.y3 = y3;
    }

    public int getY3(){
        return this.y3;
    }

    public double calcularArea(){
        double area = Math.abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
        return area;
    }

    public double calcularPerimetro(){
            double distancia1 = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            double distancia2 = Math.sqrt(Math.pow(x3 - x2, 2) + Math.pow(y3 - y2, 2));
            double distancia3 = Math.sqrt(Math.pow(x1 - x3, 2) + Math.pow(y1 - y3, 2));
            double perimetro = distancia1 + distancia2 + distancia3;
            return perimetro;
    }
    
    public double calcularAltura() {
        int minY = Math.min(y1, Math.min(y2, y3));
        int maxY = Math.max(y1, Math.max(y2, y3));
        double altura = maxY - minY;
        return altura;
        
    }
}