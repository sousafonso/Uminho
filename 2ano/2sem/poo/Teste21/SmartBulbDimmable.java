package Teste21;

public class SmartBulbDimmable extends SmartBulb {
    // Current intensity in percent (0 to 100)
    private double intensidade;
    // Flag to indicate if the lamp is being turned on for the first time
    private boolean firstTime;
    
    /**
     * Construtor parametrizado
     * @param id identificação do dispositivo
     * @param tone tonalidade da lâmpada (WARM, NEUTRAL ou COLD)
     * @param consumoPorHora consumo anunciado por hora quando a lâmpada está a 100%
     */
    public SmartBulbDimmable(String id, int tone, double consumoPorHora) {
        super(id, tone, consumoPorHora);
        // Initially, the lamp is off. When turned on for the first time,
        // it will adjust the intensity.
        this.intensidade = 0;
        this.firstTime = true;
    }
    
    /**
     * Liga a lâmpada. Se for a primeira vez a ser ligada, define a intensidade para 50%
     * e ajusta o consumo para metade do valor anunciado.
     */
    public void ligar() {
        if (firstTime) {
            // Set intensity to 50% on first activation
            this.intensidade = 50.0;
            this.firstTime = false;
        }
        // Se existir implementação na superclasse para ligar, pode ser invocada aqui:
        // super.ligar();
    }
    
    /**
     * Retorna o consumo por hora ajustado à intensidade atual.
     * Quando a lâmpada estiver a 50%, retorna metade do consumo anunciado.
     * Para intensidades diferentes, presume-se que o consumo é proporcional à intensidade.
     * @return consumo por hora real
     */
    @Override
    public double getConsumoPorHora() {
        // O consumo real é proporcional à intensidade (em percentagem)
        return (this.intensidade / 100.0) * super.getConsumoPorHora();
    }
    
    /**
     * Método para obter a intensidade atual da lâmpada.
     * @return intensidade (0 a 100)
     */
    public double getIntensidade(){
        return this.intensidade;
    }
    
    /**
     * Define a intensidade da lâmpada.
     * Limita a intensidade entre 0 e 100.
     * @param intensidade nova intensidade (em percentagem)
     */
    public void setIntensidade(double intensidade){
        if (intensidade < 0)
            this.intensidade = 0;
        else if (intensidade > 100)
            this.intensidade = 100;
        else
            this.intensidade = intensidade;
    }
    
    // Se existirem outros métodos herdados que precisem de ser reescritos,
    // estes devem ser implementados conforme a necessidade.
}
