import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Treino {
    public void numerosPares(){
        List<Integer> numeros = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        numeros.stream().filter(x -> x % 2 == 0).forEach(System.out::println);
    }

    public void maiusculas(){
        List<String> palavras = Arrays.asList("java", "stream", "exercicio", "aprendizado");
        palavras.stream().map(String::toUpperCase).forEach(System.out::println);
    }

    public void soma (){
        List<Integer> numeros = Arrays.asList(5, 10, 15, 20);
        numeros.stream().sum();
    }

    public void ordem (){
        List<Integer> numeros = Arrays.asList(5, 2, 9, 1, 7, 3, 8, 4, 6);
        // Ordem crescente
        List<Integer> crescente = numeros.stream().sorted().collect(Collectors.toList());

        // Ordem decrescente
        List<Integer> decrescente = numeros.stream().
            // seu código aqui
    }

    public void ordPorTamanho(){
        List<String> palavras = Arrays.asList("banana", "maçã", "laranja", "kiwi", "uva");
        List<String> porTamanho = palavras.stream().
    }
}
