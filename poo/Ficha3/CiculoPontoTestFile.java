import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

class CirculoPontoTestFile {
    private CirculoPonto circulo;

    @Before
    public void setUp() {
        circulo = new CirculoPonto(5, new Ponto(1, 1));
    }

    @Test
    public void testCalculaArea() {
        // A área de um círculo de raio 5 é 78.53981633974483
        assertEquals(78.53981633974483, circulo.calculaArea(), 0.0001);
    }

    @Test
    public void testCalculaPerimetro() {
        // O perímetro de um círculo de raio 5 é 31.41592653589793
        assertEquals(31.41592653589793, circulo.calculaPerimetro(), 0.0001);
    }

    @Test
    public void testSetEGetRaio() {
        circulo.setRaio(10);
        assertEquals(10, circulo.getRaio());
    }

    @Test
    public void testAlteracoesCentro() {
        circulo.alteraCentro(2, 3);
        assertEquals(2, circulo.getX());
        assertEquals(3, circulo.getY());
    }
}

