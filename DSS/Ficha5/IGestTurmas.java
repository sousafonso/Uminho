public interface IGestTurmas {
    public Aluno getAluno ( String codAluno );
    float getNotaAluno ( String codAluno );
    void registaEntrega ( Entrega e , String codGrupo );
    boolean validaAvaliadores ();
}