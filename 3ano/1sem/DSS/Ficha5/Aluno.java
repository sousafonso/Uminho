public class Aluno extends Pessoa implements Identificavel {
    private Grupo meuGrupo ;
    private String numAluno ;
    private int notaTeo ;
    private int bounsPrat ;
    public void regista ( Grupo g ) { 
        meuGrupo = g ;
    }
    public String getID () { 
        return numAluno ;
    }
    public void setNome ( String n ) { 
        nome = n ;
    }
}