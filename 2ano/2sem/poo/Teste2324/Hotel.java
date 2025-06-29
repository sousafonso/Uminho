import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class Hotel {
    private String nome;
    // Utilizamos Map para acesso rápido aos quartos através do número
    protected Map<String, Quarto> quartosHotel;
    // Utilizamos Map para associar cada quarto ao registo de ocupação corrente
    protected Map<Quarto, Registo> registos;

    public Hotel(String nome) {
        this.nome = nome;
    }
    
    // Construtor que cria o Hotel a partir de um Iterator de quartos
    public Hotel(Iterator<Quarto> quartos) {
        this.nome = "";
        this.quartosHotel = new HashMap<>();
        this.registos = new HashMap<>();
        while (quartos.hasNext()){
            Quarto q = quartos.next();
            this.quartosHotel.put(q.getNumeroQuarto(), q);
        }
    }
    
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public Map<String, Quarto> getQuartos() {
        return quartosHotel;
    }
    public void setQuartos(Map<String, Quarto> quartos) {
        this.quartosHotel = quartos;
    }
    public Map<Quarto, Registo> getRegistos() {
        return registos;
    }
    public void setRegistos(Map<Quarto, Registo> registos) {
        this.registos = registos;
    }
    
    // Adiciona um registo de ocupação para um quarto, se este existir.
    public void adicionaRegisto(LocalDate entrada, LocalDate saida, String numQuarto) {
        Quarto quarto = quartosHotel.get(numQuarto);
        if (quarto != null) {
            // O id é atribuído automaticamente (sequencial simples)
            int novoId = registos.size() + 1;
            Registo registo = new Registo(novoId, entrada, saida, quarto);
            registos.put(quarto, registo);
        } else {
            System.out.println("Quarto não encontrado.");
        }
    }
    
    // Método auxiliar que retorna o total de dias ocupados neste hotel (soma de todos os registos)
    public int getTotalDiasOcupacao() {
        int total = 0;
        for (Registo reg : registos.values()) {
            total += reg.numDiasReserva();
        }
        return total;
    }
    
    // Considerando que já existe o método quartosLivres(LocalDate, LocalDate) que pode lançar excepção
    public List<Quarto> quartosLivres(LocalDate entrada, LocalDate saida) throws SemDisponibilidadeException {
        List<Quarto> livres = new ArrayList<>();
        for (Quarto q : quartosHotel.values()) {
            // Para efeito deste exemplo, assume-se que se não existir registo para o quarto ou o registo
            // não conflita com as datas pretendidas, então o quarto é livre.
            if (!registos.containsKey(q)) {
                livres.add(q);
            }
        }
        if (livres.isEmpty()) {
            throw new SemDisponibilidadeException("Não há quartos livres.");
        }
        return livres;
    }
    
    // Método para reservar um quarto para hóspedes seniores. 
    // idades: lista com as idades dos ocupantes
    public void reservaQuartoSenior(LocalDate entrada, LocalDate saida, String numQuarto, List<Integer> idades) {
        Quarto quarto = quartosHotel.get(numQuarto);
        if (quarto instanceof QuartoDuploSenior) {
            boolean todosSeniors = true;
            for (int idade : idades) {
                if (idade < 60) {
                    todosSeniors = false;
                    break;
                }
            }
            if (todosSeniors) {
                int novoId = registos.size() + 1;
                // O método valorAPagar() de Registo poderá ser sobreposto para aplicar o desconto (veja abaixo)
                Registo registo = new Registo(novoId, entrada, saida, quarto);
                registos.put(quarto, registo);
            } else {
                System.out.println("Um ou mais ocupantes não são seniores.");
            }
        } else {
            System.out.println("Quarto não é do tipo QuartoDuploSenior.");
        }
    }
    
    // Outros métodos existentes...
}
