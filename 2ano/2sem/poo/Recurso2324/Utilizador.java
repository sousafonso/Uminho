package Recurso2324;

import java.util.List;
import java.util.Map;

public class Utilizador {
    private String email; // chave que identifica um utilizador
    private Map<String, Atividade> atividades; // codigo actividade --> Atividade
    private PlanoDeTreino plano;

    public Utilizador(Utilizador u){
        this.email = u.getEmail();
        this.atividades = u.getAtividades();
    }

    public String getEmail() {
        return email;
    }

    public Map<String, Atividade> getAtividades() {
        return atividades;
    }

    public PlanoDeTreino getPlanoTreino() {
        return plano;
    }

    public void adicionaActividade(Atividade a, int sessaoTreino) 
        throws IllegalArgumentException, IllegalStateException {
        
        if (a == null) {
            throw new IllegalArgumentException("Atividade não pode ser nula");
        }
        
        if (sessaoTreino < 0 || sessaoTreino > 6) {
            throw new IllegalArgumentException("Sessão inválida (0-6)");
        }
        
        if (this.plano == null) {
            throw new IllegalStateException("Utilizador não tem plano de treino");
        }
        
        List<SessaoTreino> sessoes = plano.getSessoes();
        
        // Verifica se a sessão existe, se não, cria
        while (sessoes.size() <= sessaoTreino) {
            sessoes.add(new SessaoTreino(sessoes.size()));
        }
        
        SessaoTreino sessao = sessoes.get(sessaoTreino);
        sessao.getAtividades().add(a);
    }

}
