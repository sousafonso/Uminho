import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class Hotel implements Serializable {
    private String nome;
    private Map<String, Quarto> quartos;
    private List<Registo> registos;

    public Hotel(Iterator<Quarto> quartos) {
        this.nome = "Hotel";
        this.quartos = new HashMap<>();
        while (quartos.hasNext()) {
            Quarto q = quartos.next();
            this.quartos.put(q.getNumeroQuarto(), q.clone());
        }
        this.registos = new ArrayList<>();
    }

    public void adicionaRegisto(LocalDate entrada, LocalDate saida, String numQuarto) throws IllegalArgumentException {
        if (!quartos.containsKey(numQuarto)) { // ver se o quarto existe
            throw new IllegalArgumentException("Quarto com número " + numQuarto + " não existe.");
        }
        if (entrada.isAfter(saida)) {
            throw new IllegalArgumentException("Data de entrada não pode ser posterior à data de saída.");
        }

        Quarto quarto = quartos.get(numQuarto);
        Registo registo = new Registo(entrada, saida, quarto);
        registos.add(registo);
    }

    public void reservaQuartoSenior(LocalDate entrada, LocalDate saida, String numQuarto, int idade1, int idade2) 
            throws IllegalArgumentException {
        if (!quartos.containsKey(numQuarto) || !(quartos.get(numQuarto) instanceof QuartoDuploSenior)) { 
            // se o quarto nao existir ou não for do tipo QuartoDuploSenior
            throw new IllegalArgumentException("Quarto não é do tipo QuartoDuploSenior.");
        }
        if (idade1 < 60 || idade2 < 60) {
            throw new IllegalArgumentException("Ocupantes devem ter 60 anos ou mais.");
        }
        adicionaRegisto(entrada, saida, numQuarto);
    }
}