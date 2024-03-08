public class Triangulo{
    private Int x1, x2, x3, y1, y2, y3;

    public Triangulo(Int x1, Int x2, Int x3, Int y1, Int y2, Int y3){
        this.x1 = x1;
        this.x2 = x2;
        this.x3 = x3;
        this.y1 = y1;
        this.y2 = y2;
        this.y3 = y3;
    }

    public void setX1(Int x1){
        this.x1 = x1;
    }

    public Int getX1(){
        return this.x1;
    }

    public void setX2(Int x2){
        this.x2 = x2;
    }

    public Int getX2(){
        return this.x2;
    }

    public void setX3(Int x3){
        this.x3 = x3;
    }

    public Int getX3(){
        return this.x3;
    }

    public void setY1(Int y1){
        this.y1 = y1;
    }

    public Int getY1(){
        return this.y1;
    }

    public void setY2(Int y2){
        this.y2 = y2;
    }

    public Int getY2(){
        return this.y2;
    }

    public void setY3(Int y3){
        this.y3 = y3;
    }

    public Int getY3(){
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