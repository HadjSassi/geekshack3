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

        int tempEcoule_Int1 = Integer.parseInt(line1[1]);
        int newTempsEcoule_Int1= Integer.parseInt(line2[1]);
        //int newTempsEcoule_Int2= Integer.parseInt(line2[2]);

        int outTemps;

        if (tempEcoule_Int1 < newTempsEcoule_Int1){
            outTemps = tempEcoule_Int1 * 2;
            System.out.println(outTemps);
        }else if(tempEcoule_Int1 > newTempsEcoule_Int1){
            outTemps = newTempsEcoule_Int1 + tempEcoule_Int1;
            System.out.println(outTemps);
            /*if(tempEcoule_Int1 > newTempsEcoule_Int2){
                outTemps = newTempsEcoule_Int1 + (newTempsEcoule_Int2 - newTempsEcoule_Int1) + tempEcoule_Int1;
                System.out.println(outTemps);
            }*/
        }

    }
    
}