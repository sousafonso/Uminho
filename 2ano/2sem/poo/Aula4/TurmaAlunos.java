package Aula4;

import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class TurmaAlunos {
    Map<String, Aluno> turma;

    public TurmaAlunos() {
        this.turma = new HashMap<>();
    }

    public void getAluno(String numero) {
        return turma.get(numero);
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || this.getClass() != o.getClass()) {
            return false;
        }
        TurmaAlunos turma = (TurmaAlunos) o;
        return this.turma.equals(turma.turma);
    }

    public TurmaAlunos clone() {
        TurmaAlunos turma = new TurmaAlunos();
        for (Map.Entry<String, Aluno> entry : this.turma.entrySet()) {
            turma.turma.put(entry.getKey(), entry.getValue().clone());
        }
        return turma;
    }

    public boolean compareTo(TurmaAlunos turma) {
        return this.turma.equals(turma.turma);
    }

    /**
     * Método que insere um aluno na turma
     * @param a
     */
    public void insereAluno(Aluno a) {
        turma.put(a.getNumero(), a);
    }

    /**
     * Método que devolve um aluno da turma dado o seu código
     * @param codAluno
     * @return
     */
    public Aluno getAluno(String codAluno){
        return turma.get(codAluno);
    }

    /**
     * Método que remove um aluno da turma dado o seu código
     * @param codAluno
     */
    public void removeAluno(String codAluno){
        return turma.remove(codAluno);
    }

    /**
     * Método que devolve o número de alunos na turma
     * @return
     */
    public Set<String> todosOsCodigo() {
        return new HashSet<>(this.turma.keySet());
    }

    /**
     * Método que devolve o número de alunos na turma
     * @return
     */
    public int qtsAlunos(){
        return this.turma.size();
    }

    /**
     * Método que devolve os alunos distribuídos por ordem alfabética crescente
     * @return
     */
    public Collection<Aluno> alunosOrdemAlfabetica() {
        return this.alunos.values().stream()
                .sorted(Comparator.comparing(Aluno::getNome))
                .collect(Collectors.toList());
    }

    /**
     * Método que devolve os alunos distribuídos por ordem alfabética decrescente
     * @return
     */
    public Set<Aluno> alunosOrdemDescrescenteNumero(){
        return this.alunos.values().stream()
                .sorted(Comparator.comparing(Aluno::getNumero)).reversed()
                .collect(Collectors.toList());
    }
}
