package Recurso2324;

import java.util.ArrayList;
import java.util.List;

public class SessaoTreino {
    private List<Atividade> atividades;
    private int diaSemana; // // 0=domingo, 1=segunda, ..., 6=sábado

    public SessaoTreino(int diaSemana) {
        this.diaSemana = diaSemana;
        this.atividades = new ArrayList<>();
    }

    public List<Atividade> getAtividades(){
        return this.atividades;
    }
}
