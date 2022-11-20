import java.util.Scanner;

public class Main {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String line1[] ;
        String tempEcoule_Ch = sc.nextLine();
        line1 = tempEcoule_Ch.split(" ");
        String line2[] ;
        String newTempsEcoule_Ch = sc.nextLine();
        line2 = newTempsEcoule_Ch.split(" ");

        int tempEcoule_Int = Integer.parseInt(tempEcoule_Ch);
        int newTempsEcoule_Int = Integer.parseInt(newTempsEcoule_Ch);

        int outTemps;

        if (tempEcoule_Int < newTempsEcoule_Int){
            outTemps = tempEcoule_Int * 2;
        }else if(tempEcoule_Int > newTempsEcoule_Int){
            outTemps = newTempsEcoule_Int + tempEcoule_Int;
        }
    }
}
