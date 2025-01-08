import java.util.Scanner;

public class DiffTemps{
    public static void main(String[] args){

    }

    public void difftemps(){
        Scanner input = new Scanner(System.in);

        System.out.prinln("Quantos dias deseja avaliar?");
        int n = input.nextInt();
        int temp1, d1, d2, delta = 0, media = 0;

        for (int i = 1; i <= n; i++){
            System.out.println ("Indique a temperatura do %dºdia: ", i);
            if (i == 1) temp1 = input.nextInt();
            
            media += temp1;
        }

        media = media / n;
    }
}