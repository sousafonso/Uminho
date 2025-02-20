import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.List;

public class DataArray {
    private List<LocalDate> datas = new ArrayList<>();

    // (a) Inserir uma nova data
    public void insereData(LocalDate data) {
        datas.add(data);
    }

    // (b) Dada uma data, retorna a data do array mais próxima
    public LocalDate dataMaisProxima(LocalDate data) {
        if (datas.isEmpty()) return null;
        LocalDate maisProxima = datas.get(0);
        long minDiff = Math.abs(ChronoUnit.DAYS.between(data, maisProxima));
        for (LocalDate d : datas) {
            long diff = Math.abs(ChronoUnit.DAYS.between(data, d));
            if (diff < minDiff) {
                minDiff = diff;
                maisProxima = d;
            }
        }
        return maisProxima;
    }

    // (c) Devolver uma String com todas as datas
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (LocalDate d : datas)
            sb.append(d).append(" ");
        return sb.toString().trim();
    }
}
