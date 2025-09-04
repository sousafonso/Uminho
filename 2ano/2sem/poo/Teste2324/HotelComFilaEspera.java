import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class HotelComFilaEspera extends Hotel implements Serializable {
    private List<Registo> reservasEmEspera;

    public HotelComFilaEspera(Iterator<Quarto> quartos) {
        super(quartos);
        this.reservasEmEspera = new ArrayList<>();
    }

    public void adicionaReserva(LocalDate entrada, LocalDate saida) {
        List<Quarto> quartosLivres;
        try {
            quartosLivres = quartosLivres(entrada, saida);
            if (!quartosLivres.isEmpty()) {
                adicionaRegisto(entrada, saida, quartosLivres.get(0).getNumeroQuarto());
            } else {
                // Adiciona à fila de espera (usando um quarto genérico para o registo)
                Quarto quartoPlaceholder = quartos.values().iterator().next().clone();
                Registo registo = new Registo(entrada, saida, quartoPlaceholder);
                reservasEmEspera.add(registo);
            }
        } catch (SemDisponibilidadeException e) {
            Quarto quartoPlaceholder = quartos.values().iterator().next().clone();
            Registo registo = new Registo(entrada, saida, quartoPlaceholder);
            reservasEmEspera.add(registo);
        }
    }

    public void ocupaQuartoComReservaEmEspera() {
        if (reservasEmEspera.isEmpty()) {
            return;
        }

        Registo reserva = reservasEmEspera.get(0);
        List<Quarto> quartosLivres;
        try {
            quartosLivres = quartosLivres(reserva.getDataInicio(), reserva.getDataFim());
            if (!quartosLivres.isEmpty()) {
                adicionaRegisto(reserva.getDataInicio(), reserva.getDataFim(), quartosLivres.get(0).getNumeroQuarto());
                reservasEmEspera.remove(0);
            }
        } catch (SemDisponibilidadeException e) {
            // Não faz nada, espera por nova tentativa
        }
    }
}