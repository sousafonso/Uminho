package Teste21;

import java.util.*;

public class CasaInteligente {
    private Map<String, List<SmartDevice>> smartHouse;

    public CasaInteligente(Collection<SmartDevice> devices){
        this.smartHouse = new HashMap<>();
        for (SmartDevice device : devices) {
            String divisao = device.getDivisao();
            if (!this.smartHouse.containsKey(divisao)) {
                this.smartHouse.put(divisao, new ArrayList<>());
            }
            this.smartHouse.get(divisao).add(device);
        }
    }

    public void remove(String id) throws Exception {
        for (List<SmartDevice> devices : this.smartHouse.values()) {
            for (SmartDevice device : devices) {
                if (device.getId().equals(id)) {
                    devices.remove(device);
                    return;
                }
            }
        }
        throw new Exception("Dispositivo não encontrado");
    }

    public Iterator<SmartDevice> devicesPorConsumoCrescente(){
        List<SmartDevice> sortedDevices = new ArrayList<>();
        for (List<SmartDevice> devices : this.smartHouse.values()) {
            sortedDevices.addAll(devices);
        }
        Collections.sort(sortedDevices, new Comparator<SmartDevice>() {
            public int compare(SmartDevice d1, SmartDevice d2) {
                return Double.compare(d1.getConsumo(), d2.getConsumo());
            }
        });
        return sortedDevices.iterator();
    }

    public String divisaoMaisEconomica(){
        String divisaoMaisEconomica = null;
        double menorConsumo = Double.MAX_VALUE;

        for (Map.Entry<String, List<SmartDevice>> entry : this.smartHouse.entrySet()) {
            String divisao = entry.getKey();
            List<SmartDevice> devices = entry.getValue();
            double totalConsumo = 0;

            for (SmartDevice device : devices) {
                totalConsumo += device.totalConsumo();
            }

            if (totalConsumo < menorConsumo) {
                menorConsumo = totalConsumo;
                divisaoMaisEconomica = divisao;
            }
        }
        return divisaoMaisEconomica;
    }
}
