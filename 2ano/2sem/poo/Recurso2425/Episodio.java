package Recurso2425;

import java.time.LocalDate;

public class Episodio {
    private int duracao;
    private String titulo;
    private LocalDate lancamento;
    private byte [] conteudo;

    public int getDuracao(){
        return this.duracao;
    }
}
