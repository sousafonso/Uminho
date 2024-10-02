public class Sensor{
    private double pressao;

    // Construtor padrão que inicializa a pressão com zero
    public Sensor() {
        this.pressao = 0;
    }

    // Construtor parametrizado que inicializa a pressão com o valor fornecido
    public Sensor(double valor) {
        if (valor >= 0) {
            this.pressao = valor;
        } else {
            this.pressao = 0;
        }
    }

    public boolean setPressao(double valor){
        if(this.pressao > 0) this.pressao = valor; return true;
        else return false;
    }

    public double getPressao(){
        return this.pressao;
    }

    public static void main(String[] args) {
        // Testando o construtor padrão
        Sensor sensor1 = new Sensor();
        System.out.println("Pressão inicial do sensor1: " + sensor1.getPressao());

        // Testando o construtor parametrizado
        Sensor sensor2 = new Sensor(10.5);
        System.out.println("Pressão inicial do sensor2: " + sensor2.getPressao());

        // Tentando atualizar a pressão para um valor válido
        boolean atualizou = sensor2.setPressao(15.0);
        System.out.println("Atualização da pressão para 15.0 foi bem-sucedida? " + atualizou);
        System.out.println("Pressão atual do sensor2: " + sensor2.getPressao());

        // Tentando atualizar a pressão para um valor inválido
        atualizou = sensor2.setPressao(-5.0);
        System.out.println("Atualização da pressão para -5.0 foi bem-sucedida? " + atualizou);
        System.out.println("Pressão atual do sensor2: " + sensor2.getPressao());
    }
}