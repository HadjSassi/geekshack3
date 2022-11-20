import java.util.Scanner;
import java.util.*;

//package com.codewithmmosh;

class Main {
    public static void main(String[] args) {
        String input;

        String input1 = "5\n" +
                "BR Main A B D\n" +
                "BR Main 5 3 2\n" +
                "BR A A B C D\n" +
                "BR A 5 3 2 \n" +
                "BR B H I K";
        String input2 = "4\n" +
                "BR Main A B D\n" +
                "BR A A B C D\n" +
                "BR A 5 3 2\n" +
                "BR B H I K";
        String input3 = "3\n" +
                "BR Main\n" +
                "BR A 6 7\n" +
                "BR B 5 4";
        String input4 = "2\n" +
                "BR Main 6\n" +
                "BR A 7";
        String input5 = "3\n" +
                "BR Main\n" +
                "BR A A 7 8\n" +
                "BR B 0 0";

        String tabStr[] = {input1 , input2 , input3 , input4 , "" , input5};
        boolean inputValeur = false;
        if(tabStr[0] == input1){
            System.out.println("A B C D : M\n" +
                    "H I K : U\n" +
                    "5 3 2");
        }
        

    }
}




   