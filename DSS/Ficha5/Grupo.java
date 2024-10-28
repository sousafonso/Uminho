import java.util.List ;

public class Grupo implements Identificavel {
    private String cod ;
    private int nota ;
    private List < Entrega > entregas ;
    public void addEntrega ( Entrega e ) { 
        entregas.add(e) ;
    }
    public String getID () { 
        return cod ;
    }
    }