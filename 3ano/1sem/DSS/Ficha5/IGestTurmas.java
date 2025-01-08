public interface IGestTurmas {
    public Aluno getAluno ( String codAluno );
    public int getNotaAluno(String codAluno);
    void registaEntrega ( Entrega e , String codGrupo );
    boolean validaAvaliadores ();
}