package Teste2425;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

public class MasterUber implements Serializable {
    private Map<String, UberP00> empresasLocais;
    private Map<String, Carro> carrosCentralizados;

    public MasterUber() {
        this.empresasLocais = new HashMap<>();
        this.carrosCentralizados = new HashMap<>();
    }

    public void forneceCarro(Carro c, String empresaLocal) throws IllegalArgumentException {
        if (!empresasLocais.containsKey(empresaLocal)) {
            throw new IllegalArgumentException("Empresa " + empresaLocal + " não existe.");
        }
        if (carrosCentralizados.containsKey(c.getMatricula())) {
            throw new IllegalArgumentException("Carro com matrícula " + c.getMatricula() + " já existe.");
        }

        carrosCentralizados.put(c.getMatricula(), c.clone());
        empresasLocais.get(empresaLocal).getCarros().put(c.getMatricula(), c.clone());
    }
}