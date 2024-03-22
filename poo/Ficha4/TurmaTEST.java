import static org.junit.Assert.assertEquals;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

// import javax.swing.text.html.HTMLDocument.Iterator;

public class TurmaTEST {
    Turma turma;

    @Test
    void adicionaAlunoTest() {
        int size = turma.getAlunos().size();
        Aluno aluno = new Aluno();
        aluno.setNome("Rui");
        turma.addAluno(aluno);
        assertEquals(size + 1, turma.getAlunos().size());

    }

    @Test
    void getAlunoTest() {
        turma = new Turma();
        Aluno aluno = new Aluno();
        turma.addAluno(aluno);
        assert turma.getAluno(0).equals(aluno);
    }

    @Test
    void media(){
        assertEquals(0, turma.mediaNotas(), 0.001);
        Aluno aluno = new Aluno();
        aluno.setNotas(new int[]{10, 10, 10});
    }
}