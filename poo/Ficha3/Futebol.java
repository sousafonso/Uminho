public class Futebol{
    private String visitante;
    private String visitado;
    private Integer golsVisitante;
    private Integer golsVisitado;
    private String estado; // por iniciar, a decorrer ou terminado

    public Futebol(String visitante, String visitado, Integer golsVisitante, Integer golsVisitado, String estado){
        this.visitante = visitante;
        this.visitado = visitado;
        this.golsVisitante = golsVisitante;
        this.golsVisitado = golsVisitado;
        this.estado = estado;
    }

    public void setVisitante(String visitante){
        this.visitante = visitante;
    }

    public String getVisitante(){
        return this.visitante;
    }

    public void setVisitado(String visitado){
        this.visitado = visitado;
    }

    public String getVisitado(){
        return this.visitado;
    }

    public void setGolsVisitante(Integer golsVisitante){
        this.golsVisitante = golsVisitante;
    }

    public Integer getGolsVisitante(){
        return this.golsVisitante;
    }

    public void setGolsVisitado(Integer golsVisitado){
        this.golsVisitado = golsVisitado;
    }

    public Integer getGolsVisitado(){
        return this.golsVisitado;
    }

    public void setEstado(String estado){
        this.estado = estado;
    }

    public String getEstado(){
        return this.estado;
    }
    
    public void startGame(){
        this.estado = "a decorrer";
    }


    public void endGame(){
        this.estado = "terminado";
    }

    public void golsVisitante(){
        this.golsVisitante++;
    }

    public void golsVisitado(){
        this.golsVisitado++;
    }

    public String resultadoAtual(){
        return this.visitante + " " + this.golsVisitante + " - " + this.golsVisitado + " " + this.visitado;
    }

    public String resultado(){
        if(this.golsVisitante > this.golsVisitado){
            return this.visitante;
        }else if(this.golsVisitante < this.golsVisitado){
            return this.visitado;
        }else{
            return "Empate";
        }
    }
}