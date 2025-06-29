import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class HotelComFilaEspera extends Hotel {
    private List<Registo> reservasEmEspera;
    
    public HotelComFilaEspera(Iterator<Quarto> quartos) {
        super(quartos);
        reservasEmEspera = new ArrayList<>();
    }
    
    // Regista uma reserva em espera (sem atribuição de quarto)
    public void adicionaReserva(LocalDate entrada, LocalDate saida) {
        int novoId = reservasEmEspera.size() + 1;
        // Para reservas em espera, o quarto pode ser null
        Registo reserva = new Registo(novoId, entrada, saida, null);
        reservasEmEspera.add(reserva);
    }
    
    // Verifica se existe, no momento, algum quarto livre e, se existir,
    // atribui-o à reserva em espera há mais tempo (primeiro da lista)
    public void ocupaQuartoComReservaEmEspera() {
        if (!reservasEmEspera.isEmpty()) {
            Registo reserva = reservasEmEspera.get(0);
            try {
                List<Quarto> livres = this.quartosLivres(reserva.getInicio(), reserva.getFim());
                if (!livres.isEmpty()) {
                    Quarto quarto = livres.get(0);
                    int novoId = registos.size() + 1;
                    Registo novoRegisto = new Registo(novoId, reserva.getInicio(), reserva.getFim(), quarto);
                    registos.put(quarto, novoRegisto);
                    reservasEmEspera.remove(0);
                }
            } catch (SemDisponibilidadeException e) {
                // Se não houver quartos disponíveis, não faz nada.
            }
        }
    }
}