import java.time.LocalDate;
import java.util.Scanner;

public class TesteDataArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DataArray da = new DataArray();
        
        System.out.print("Quantas datas deseja inserir? ");
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print("Digite uma data (YYYY-MM-DD): ");
            LocalDate data = LocalDate.parse(sc.next());
            da.insereData(data);
        }
        System.out.println("Datas inseridas: " + da);
        
        System.out.print("Digite uma data de referência (YYYY-MM-DD): ");
        LocalDate ref = LocalDate.parse(sc.next());
        System.out.println("Data mais próxima: " + da.dataMaisProxima(ref));
    }
}
