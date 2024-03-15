package poo.Ficha4;

import java.util.ArrayList;
import java.util.List;

// import javax.swing.text.html.HTMLDocument.Iterator;

public class Turma {
    private String nome; // as Strnigs sao imutaveis, logo nao e necessario fazer clone. São constantes
    private List<Aluno> alunos;

    /**
     * @brief Construtor vazio
     */
    public Turma() {
        nome = "";
        alunos = new ArrayList<Aluno>();
    }

    public Turma(String nome, List<Aluno> alunos) {
        this.nome = nome;
        /**
         * ERRADO
         * 
         * this.alunos = alunos;  porque se for feito assim, a lista de alunos da turma vai ser a mesma lista de alunos que foi passada como argumento
         * this.alunos = new ArrayList<>(alunos); porque se for feito assim, a lista de alunos da turma vai ser uma cópia da lista de alunos que foi passada como argumento
         */
        this.alunos = new ArrayList<Aluno>();
        for (Aluno aluno : alunos) {
            this.alunos.add(aluno.clone());
        }

        // ou 

        // for (Iterator<Aluno> it = alunos.iterator(); it.hasNext();) {
        //     Aluno aluno = it.next();
        //     this.alunos.add(aluno.clone());
        // }

        // ou

        // for (int i = 0; i < alunos.size(); i++) {
        //     this.alunos.add(alunos.get(i).clone());
        // }
    }

    /**
     * @brief Construtor por cópia
     * @param turma
     */
    public Turma(Turma turma) {
        nome = turma.getNome();
        alunos = turma.getAlunos();
    }

    public Turma clone() {
        return new Turma(this);
    }

    /**
     * @brief Devolve o nome de um aluno
     * @return
     */
    public String getNome() {
        return nome;
    }

    /**
     * @brief Devolve uma cópia da lista de alunos
     * @return
     */
    public List<Aluno> getAlunos() {
        List<Aluno> res = new ArrayList<Aluno>();
        for (Aluno aluno : alunos) {
            res.add(aluno.clone());
        }
        return res;
    }

    /**
     * @brief Devolve um aluno
     * @param aluno
     * @return 
     */
    public Aluno getAluno(Aluno aluno) {
        Aluno res = null;
        for (Aluno a : alunos) {
            if (a.equals(aluno)) {
                res = a.clone();
                break;
            }
        }
        return res;
    }

    /**
     * @brief Devolve um aluno
     * @param nome
     * @return
     */

    public Aluno getAluno(String nome) {
        Aluno res = null;
        for (Aluno aluno : alunos) {
            if (aluno.getNome().equals(nome)) {
                res = aluno.clone();
                break;
            }
        }
        return res;

        // ou

        // for (int i = 0; i < alunos.size(); i++) {
        //     if (alunos.get(i).getNome().equals(nome)) {
        //         res = alunos.get(i).clone();
        //         break;
        //     }
        // }

        // ou

        // for (Iterator<Aluno> it = alunos.iterator(); it.hasNext();) {
        //     Aluno aluno = it.next();
        //     if (aluno.getNome().equals(nome)) {
        //         res = aluno.clone();
        //         break;
        //     }
        // }
    }

    /**
     * @brief Define o nome de um aluno
     * @param nome
     */
    public void setNome(String nome) {
        this.nome = nome;
    }

    /**
     * @brief Define a lista de alunos
     * @param alunos
     */
    public void setAlunos(List<Aluno> alunos) {
        this.alunos = new ArrayList<Aluno>();
        for (Aluno aluno : alunos) {
            this.alunos.add(aluno.clone());
        }
    }

    /**
     * @brief Adiciona um aluno à lista de alunos
     * @param aluno
     */
    public void addAluno(Aluno aluno) {
        this.alunos.add(aluno.clone());
    }

    /**
     * @brief Remove um aluno da lista de alunos
     * @param aluno
     */
    public void removeAluno(Aluno aluno) {
        alunos.remove(aluno);
    }

    public int numAlunos() {
        return alunos.size();
    }

    public double mediaNotas() {
        double media = 0;
        for (Aluno aluno : alunos) {
            media += aluno.mediaNotas();
        }
        return media / alunos.size();
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || this.getClass() != o.getClass()) {
            return false;
        }
        Turma turma = (Turma) o;
        return this.nome.equals(turma.getNome()) && alunos.equals(turma.getAlunos());
    }
    
}