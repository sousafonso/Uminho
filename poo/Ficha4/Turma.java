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


        // this.alunos = new ArrayList<Aluno>();
        // for (Aluno aluno : alunos) {
        //     this.alunos.add(aluno.clone());
        // }

        // ou 

        // for (Iterator<Aluno> it = alunos.iterator(); it.hasNext();) {
        //     Aluno aluno = it.next();
        //     this.alunos.add(aluno.clone());
        // }

        // ou

        // for (int i = 0; i < alunos.size(); i++) {
        //     this.alunos.add(alunos.get(i).clone());
        // }
        //
        // ou 

        this.alunos = alunos.stream().map(Aluno::clone).collect(Collectors.toList()); // ou map(a -> a.clone())
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
        return this.alunos.stream().map(Aluno::clone).collect(Collectors.toList());
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

    public boolean existeAlunoNumer (String numero){
        long count = alunos.stream().filter(a -> String.valueOf(a.getNumero()).equals(numero)).count();
        return count > 0;

        // ou
        /*
         * boolean res = false;
         * for (Aluno aluno : alunos) {
         *    if (String.valueOf(aluno.getNumero()).equals(numero)) {
         *       res = true;
         *      break;
         *   }
         * }
         * 
         * return res;
         */
    }
    
    public boolean existeAlunoNome(String nome) {
        long count = alunos.stream().filter(a -> a.getNome().equals(nome)).count();
        return count > 0;

        // ou
        /*
         * boolean res = false;
         * for (Aluno aluno : alunos) {
         *    if (aluno.getNome().equals(nome)) {
         *       res = true;
         *      break;
         *   }
         * }
         * 
         * return res;
         */
    }

    public List <Aluno> alunosOrdemNumero() {
        return alunos.stream().sorted(Comparator.comparing(Aluno::getNumero)).collect(Collectors.toList());
    }

    public List <Aluno> alunosOrdemDecrescenteNota() {
        return alunos.stream().sorted(Comparator.comparing(Aluno::getNota).reversed()).collect(Collectors.toList());
    }

    public Aluno getNota (String nome) {
        return alunos.stream().filter(a -> a.getNome().equals(nome)).findFirst().orElse(null);
    }

    /**
     * @brief Devolve um conjunto de alunos ordenados por ordem alfabética
     * @return
     */
    public Set <Aluno> alunosOrdemAlfabetica() {
        return alunos.stream().sorted(Comparator.comparing(Aluno::getNome)).collect(Collectors.toSet());

        // ou

        // return alunos.stream().sorted((a1, a2) -> a1.getNome().compareTo(a2.getNome())).collect(Collectors.toSet());

        // ou

        /*
         * Set <Aluno> res = new TreeSet<>(new Comparator<Aluno>() {
         *   public int compare(Aluno a1, Aluno a2) {
         *     return a1.getNome().compareTo(a2.getNome());
         * 
         *  }
         * });
         * 
         * res.addAll(alunos);
         * return res;
         * 
         */
    }

    public Aluno MelhorAluno() {
        return alunos.stream().max(Comparator.comparing(Aluno::mediaNotas)).orElse(null);
        // return alunos.strem()
    }

    public List <Aluno> alunosOrdemDecrescenteNumero() {
        return alunos.stream().sorted(Comparator.comparing(Aluno::getNumero).reversed()).collect(Collectors.toList());
    }

    public Set <Aluno> alunosAprovados() {
        return alunos.stream().filter(a -> a.mediaNotas() >= 10).collect(Collectors.toSet());
    }
    
}