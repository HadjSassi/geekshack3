package com.codewithmmosh;

import java.util.Scanner;

class Main {
    public static void main(String[] args) {

        try {
            Scanner sc = new Scanner(System.in);
            String line1 = sc.nextLine();
            String line2 = sc.nextLine();

            String[] line3;
            String prix11 = sc.nextLine();
            line3 = prix11.split(" ");

            String[] line4;
            String prix12 = sc.nextLine();
            line4 = prix12.split(" ");

            String[] line5;
            String prix13 = sc.nextLine();
            line5 = prix13.split(" ");

            int budget = Integer.parseInt(line1);
            int nbTypeMachine = Integer.parseInt(line2);
            int prix1 = Integer.parseInt(line3[1]);
            int prix2 = Integer.parseInt(line4[1]);
            int prix3 = Integer.parseInt(line5[1]);
            int prixs [] = {prix1 , prix2 , prix3};
            int s = 0;
            int x[] = {0,1,2};
            
            for (int i = 0; i < nbTypeMachine; i++) {
                s += x[i]*prixs[i];
            }
            while (s < budget){

            }

        }catch (Exception err){
            //System.out.println(err.getMessage());
        }


    }

}



 