package Recurso2324;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Fitness {
    private Map<String, Utilizador> users;


    public List<Utilizador> utilizadoresComPlano() {
        return users.values().stream()
            .filter(u -> u.getPlanoTreino() != null)
            .collect(Collectors.toList());
    }

    public Map<String, Integer> caloriasPorUtilizador() {
        return users.values().stream()
            .collect(Collectors.toMap(
                Utilizador::getEmail,
                u -> u.getAtividades().values().stream()
                    .mapToInt(a -> (int) a.caloriasGastas(u))
                    .sum()
            ));
    }

}
