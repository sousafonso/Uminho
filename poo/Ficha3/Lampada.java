public class Lampada {
    private double consumo;

    private boolean estado;

    private double maxPotencia;

    public Lampada(){
        this.consumo = 0;
        this.estado = false;
        this.maxPotencia = 0;
    }

    public void lampON(){
        this.estado = true;
    }

    public void lampOFF(){
        this.estado = false;
    }

    public void lampECO(){
        this.estado = true;
    }

    public void setMaxPotencia(double maxPotencia){
        this.maxPotencia = maxPotencia;
    }

    public double getConsumo(){
        return this.consumo;
    }

    public boolean getEstado(){
        return this.estado;
    }

    public double getMaxPotencia(){
        return this.maxPotencia;
    }

    public String toString(){
        return "A lampada tem um consumo total:" + this.getConsumo() + "estado:" + this.getEstado() + "e maxPotencia:" + this.getMaxPotencia();
    }

    public void setConsumo(double consumo){
        this.consumo = consumo;
    }

    public void setEstado(boolean estado){
        this.estado = estado;
    }

    public void alteraMaxPotencia(double maxPotencia){
        setMaxPotencia(maxPotencia);
    }

    public void ligaLampada(){
        lampON();
    }

    public void desligaLampada(){
        lampOFF();
    }

    public void ligaLampadaEco(){
        lampECO();
    }


}