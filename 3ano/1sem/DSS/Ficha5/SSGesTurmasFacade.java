import java.util.List;
import java.util.Map;

public class SSGesTurmasFacade implements IGestTurmas {
    private Docente responsavel ;
    private List < Docente > docentes_praticas ;
    private Map < String , Aluno > alunos ;
    private List < Grupo > grupos ;

    public void addDocente ( Docente d ) { 
        docentes_praticas.add(d) ;
    }

    public void addAluno ( Aluno a ) { 
        alunos.put(a.getID(), a) ;
    }

    public void addGrupo ( Grupo g ) { 
        grupos.add(g) ;
    }

    public void addResponsavel ( Docente d ) { 
        responsavel = d ;
    }

    public void inscreveAluno ( String numAluno , String codGrupo ) { 
        Aluno a = alunos.get(numAluno) ;
        Grupo g = grupos.stream().filter(gr -> gr.getID().equals(codGrupo)).findFirst().get() ;
        a.regista(g) ;
    }

    public void addEntrega ( String codGrupo , Entrega e ) { 
        Grupo g = grupos.stream().filter(gr -> gr.getID().equals(codGrupo)).findFirst().get() ;
        g.addEntrega(e) ;
    }

    public Aluno getAluno ( String codAluno ) { 
        return alunos.get(codAluno) ;
    }

    @Override
    public float getNotaAluno(String codAluno) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'getNotaAluno'");
    }

    @Override
    public void registaEntrega(Entrega e, String codGrupo) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'registaEntrega'");
    }

    @Override
    public boolean validaAvaliadores() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'validaAvaliadores'");
    }
}