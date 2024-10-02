package Aula3;

import java.util.ArrayList;
import java.util.Set;
import java.util.stream.Collectors;

import Aula2.Lampada;

public class CasaInteligente {
    ArrayList<Lampada> lampadas;

    public CasaInteligente(){
        lampadas = new ArrayList<>();
    }

    public void addLampada(Lampada l){
        lampadas.add(l);
    }

    public void ligaLampadaNormal(int index){
        lampadas.get(index).lampON();
    }

    public void ligaLampadaEco(int index){
        lampadas.get(index).lampECO();
    }

    public int qtEmEco(){
        int count = 0;
        for(Lampada l : lampadas){
            if(l.getEstado() == Lampada.Estado.ECO) count++;
        }
        return count;
    }

    public void removeLampada(int index){
        lampadas.remove(index);
    }

    public void ligaTodasEco(){
        for(Lampada l : lampadas){
            l.lampECO();
        }
    }

    public void ligaTodasMax(){
        for(Lampada l : lampadas){
            l.lampON();
        }
    }

    public double consumoTotal(){
        int consumo = 0;
        for (Lampada l : lampadas){
            consumo += consumoTotal;
        }
        return consumo;
    }

    public Lampada maisGastadora(){
        Lampada l = lampadas.get(0);
        for(Lampada l : lampadas){
            if (l.getConsumoTotal() > l.getConsumoTotal()){
                l = l;
            }
        }
    }

    public Set<Lampada> lampadasEmModoEco(){
        ArrayList <Lampada> lampadasEco = new ArrayList<>();
        for(Lampada l : lampadas){
            if(l.getEstado() == Lampada.Estado.ECO){
                lampadasEco.add(l);
            }
        }
        return lampadasEco;
    }

    public Set<Lampada> lampadasEmModoEcoV2() {
        return lampadas.stream()
                .filter(l -> l.getEstadoAtual() == Lampada.Estado.ECO)
                .collect(Collectors.toSet());
    }

    public void reset() {
        lampadas.forEach(Lampada::resetPeriodoConsumo);
    }

    public Set<Lampada> podiumEconomia() {
        return lampadas.stream()
                .sorted((l1, l2) -> Double.compare(l1.totalConsumo(), l2.totalConsumo()))
                .limit(3)
                .collect(Collectors.toSet());
    }

}
