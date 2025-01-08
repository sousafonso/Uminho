import java.util.Scanner;

public class Classificacao {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o número de classificações: ");
        int n = scanner.nextInt();

        int[] intervalos = new int[4];

        for (int i = 0; i < n; i++) {
            System.out.print("Digite a classificação " + (i + 1) + ": ");
            double classificacao = scanner.nextDouble();

            if (classificacao >= 0 && classificacao < 5) {
                intervalos[0]++;
            } else if (classificacao >= 5 && classificacao < 10) {
                intervalos[1]++;
            } else if (classificacao >= 10 && classificacao < 15) {
                intervalos[2]++;
            } else if (classificacao >= 15 && classificacao <= 20) {
                intervalos[3]++;
            }
        }

        System.out.println("Número de classificações em cada intervalo:");
        System.out.println("[0, 5[: " + intervalos[0]);
        System.out.println("[5, 10[: " + intervalos[1]);
        System.out.println("[10, 15[: " + intervalos[2]);
        System.out.println("[15, 20]: " + intervalos[3]);

        scanner.close();
    }
}
