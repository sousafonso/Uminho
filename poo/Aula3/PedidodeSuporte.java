package Aula3;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

public class PedidodeSuporte {
    private String cliente;
    private LocalDateTime ti;
    private String assunto;
    private String descricao;
    private String trabalhador;
    private LocalDateTime tf;
    private String informacao;

    public PedidodeSuporte(String cliente, LocalTime ti, String assunto, String descricao) {
        this.cliente = cliente;
        this.ti = ti;
        this.assunto = assunto;
        this.descricao = descricao;
        this.trabalhador = "";
        this.tf = null;
        this.informacao = "";
    }

    public String getCliente() {
        return this.cliente;
    }

    public LocalDateTime getTi() {
        return this.ti;
    }

    public String getAssunto() {
        return this.assunto;
    }

    public String getDescricao() {
        return this.descricao;
    }

    public String getTrabalhador() {
        return this.trabalhador;
    }   

    public LocalDateTime getTf() {
        return this.tf;
    }

    public String getInformacao() {
        return this.informacao;
    }

    public void setTrabalhador(String trabalhador) {
        this.trabalhador = trabalhador;
    }

    public void setTf(LocalTime tf) {
        this.tf = tf;
    }

    public void setInformacao(String informacao) {
        this.informacao = informacao;
    }

    public void setCliente(String cliente) {
        this.cliente = cliente;
    }

    public void setTi(LocalTime ti) {
        this.ti = ti;
    }

    public void setAssunto(String assunto) {
        this.assunto = assunto;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public PedidodeSuporte clone() {
        return new PedidodeSuporte(this.cliente, this.ti, this.assunto, this.descricao);
    }
}
