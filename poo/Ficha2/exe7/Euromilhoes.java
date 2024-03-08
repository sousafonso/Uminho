package exe7;

import java.util.Arrays;
import java.util.Scanner;

public class Euromilhoes {

    public static void main(String[] args) {
        // Gerar chave aleatória
        int[] chave = gerarChave();

        // Pedir ao utilizador para introduzir os números e estrelas da sua aposta
        int[] aposta = pedirAposta();

        // Comparar a aposta com a chave gerada
        int numerosCertos = contarNumerosCertos(chave, aposta);
        int estrelasCertas = contarEstrelasCertas(chave, aposta);

        // Imprimir os resultados
        System.out.println("Resultados:");
        System.out.println("Números certos: " + numerosCertos);
        System.out.println("Estrelas certas: " + estrelasCertas);

        // Imprimir a chave 50 vezes
        for (int i = 0; i < 50; i++) {
            imprimirChave(chave, i * 2);
        }
    }

    public static int[] gerarChave() {
        int[] chave = new int[7];
        for (int i = 0; i < 5; i++) {
            chave[i] = (int) (Math.random() * 50) + 1; // Números de 1 a 50
        }
        for (int i = 5; i < 7; i++) {
            chave[i] = (int) (Math.random() * 9) + 1; // Estrelas de 1 a 9
        }
        return chave;
    }

    public static int[] pedirAposta() {
        Scanner scanner = new Scanner(System.in);
        int[] aposta = new int[7];
        System.out.println("Introduza os 5 números da aposta (de 1 a 50):");
        for (int i = 0; i < 5; i++) {
            aposta[i] = scanner.nextInt();
        }
        System.out.println("Introduza as 2 estrelas da aposta (de 1 a 9):");
        for (int i = 5; i < 7; i++) {
            aposta[i] = scanner.nextInt();
        }
        return aposta;
    }

    public static int contarNumerosCertos(int[] chave, int[] aposta) {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            if (Arrays.binarySearch(chave, aposta[i]) >= 0) {
                count++;
            }
        }
        return count;
    }

    public static int contarEstrelasCertas(int[] chave, int[] aposta) {
        int count = 0;
        for (int i = 5; i < 7; i++) {
            if (Arrays.binarySearch(chave, aposta[i]) >= 0) {
                count++;
            }
        }
        return count;
    }

    public static void imprimirChave(int[] chave, int offset) {
        for (int i = 0; i < offset; i++) {
            System.out.print("  "); // Adicionar espaços para deslocar a chave
        }
        for (int i = 0; i < chave.length; i++) {
            System.out.print(chave[i] + " ");
        }
        System.out.println();
    }
}
