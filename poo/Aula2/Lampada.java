public class Lampada {
    // Definindo os possíveis estados da lâmpada
    public enum Estado {
        DESLIGADA, ECO, LIGADA
    }

    // Variáveis de instância
    private Estado estadoAtual;
    private double consumoMaximo; // Consumo por milissegundo quando ligada
    private double consumoEco; // Consumo por milissegundo quando em modo ECO
    private long ultimoReset;
    private double consumoTotal;
    private double consumoPeriodo;

    // Construtor parametrizado
    public Lampada(double consumoMaximo, double consumoEco) {
        this.estadoAtual = Estado.DESLIGADA;
        this.consumoMaximo = consumoMaximo;
        this.consumoEco = consumoEco;
        this.ultimoReset = System.currentTimeMillis();
        this.consumoTotal = 0;
        this.consumoPeriodo = 0;
    }

    // Getters
    public Estado getEstado() {
        return estadoAtual;
    }

    public double getConsumoMaximo() {
        return consumoMaximo;
    }

    public double getConsumoEco() {
        return consumoEco;
    }

    public long getUltimoReset() {
        return ultimoReset;
    }

    public double getConsumoTotal() {
        return consumoTotal;
    }

    public double getConsumoPeriodo() {
        return consumoPeriodo;
    }

    // Atualiza o consumo baseado no estado atual e no tempo desde o último update
    private void atualizarConsumo() {
        long agora = System.currentTimeMillis();
        long tempoPassado = agora - ultimoReset;

        switch (estadoAtual) {
            case LIGADA:
                consumoTotal += tempoPassado * consumoMaximo;
                consumoPeriodo += tempoPassado * consumoMaximo;
                break;
            case ECO:
                consumoTotal += tempoPassado * consumoEco;
                consumoPeriodo += tempoPassado * consumoEco;
                break;
            default:
                break;
        }

        ultimoReset = agora;
    }

    // (a) Ligar a lâmpada no modo consumo máximo
    public void lampON() {
        atualizarConsumo();
        estadoAtual = Estado.LIGADA;
    }

    // (b) Desligar a lâmpada
    public void lampOFF() {
        atualizarConsumo();
        estadoAtual = Estado.DESLIGADA;
    }

    // (c) Ligar a lâmpada em modo ECO
    public void lampECO() {
        atualizarConsumo();
        estadoAtual = Estado.ECO;
    }

    // (d) Devolver a informação de quanto se gastou desde a criação da lâmpada
    public double totalConsumo() {
        atualizarConsumo();
        return consumoTotal;
    }

    // (e) Devolver a informação de quanto se gastou desde o último reset de consumo
    public double periodoConsumo() {
        atualizarConsumo();
        return consumoPeriodo;
    }

    // Método para resetar o consumo do período
    public void resetPeriodoConsumo() {
        atualizarConsumo();
        consumoPeriodo = 0;
        ultimoReset = System.currentTimeMillis();
    }

    // Método principal para testar a classe Lampada
    public static void main(String[] args) {
        Lampada lampada = new Lampada(0.05, 0.01); // Consumo fictício

        lampada.lampON();
        try { Thread.sleep(1000); } catch (InterruptedException e) { e.printStackTrace(); }
        lampada.lampOFF();

        System.out.println("Consumo total: " + lampada.totalConsumo());
        System.out.println("Consumo no período: " + lampada.periodoConsumo());

        lampada.resetPeriodoConsumo();
        lampada.lampECO();
        try { Thread.sleep(2000); } catch (InterruptedException e) { e.printStackTrace(); }
        lampada.lampOFF();

        System.out.println("Consumo total: " + lampada.totalConsumo());
        System.out.println("Consumo no período após reset: " + lampada.periodoConsumo());
    }
}
