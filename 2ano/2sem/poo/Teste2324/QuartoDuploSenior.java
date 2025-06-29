public class QuartoDuploSenior extends QuartoDuplo {
    // Se necessário, adicionar atributos ou construtor específico.
    public QuartoDuploSenior(String numeroQuarto, boolean vista, float preco) {
        super(numeroQuarto);
        // Aqui é preciso ajustar os valores dos atributos herdados;
        // uma abordagem é definir setters ou possuir um construtor adequado na classe QuartoDuplo.
        // Para exemplo, supõe-se que estes atributos podem ser definidos.
    }
    
    // É necessário implementar o método abstrato precoPorDia() definido em Quarto.
    @Override
    public double precoPorDia() {
        // Implementação exemplo – pode ser baseada em regras próprias para quartos sénior.
        // Por exemplo, retorna o preço base com um desconto (este desconto será complementado no valorAPagar do registo).
        return 100.0; // valor de exemplo
    }
}