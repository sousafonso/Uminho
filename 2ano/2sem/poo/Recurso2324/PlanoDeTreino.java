package Recurso2324;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class PlanoDeTreino implements Serializable {
    private List<SessaoTreino> sessoes;
    private LocalDate dataInicio;
    private LocalDate dataFim;

    public PlanoDeTreino (){
        this.sessoes = new ArrayList<> (7);
    }

    public PlanoDeTreino(LocalDate dataInicio, LocalDate dataFim) {
        this();
        this.dataInicio = dataInicio;
        this.dataFim = dataFim;
    }

    public List<SessaoTreino> getSessoes() {
        return sessoes;
    }
}
