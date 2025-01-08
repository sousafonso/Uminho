public class Exe2 {
    public double celsiusParaFarenheit(double graus){
        return graus*33.8;
    }
    
    public int maximoNumeros(int a, int b){
        return Math.max(a, b);
    }

    public String criaDescricaoConta(String nome, double saldo){
        return nome + "o seu saldo é de " + saldo;
    }

    public double eurosParaLibras(double valor, double taxaConversao){
        return valor*taxaConversao;
    }

    public long factorial(int num){
        resultado = 0;
        return num*factorial(num-1);
    }

    
}