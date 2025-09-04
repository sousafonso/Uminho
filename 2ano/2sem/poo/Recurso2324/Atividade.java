package Recurso2324;

import java.io.Serializable;
import java.time.LocalDate;

public abstract class Atividade implements Serializable {
    private String codigo;
    private String descricao;
    private LocalDate data;
    private int duracao;
    private Utilizador user;

    public abstract double caloriasGastas(Utilizador u);

}
