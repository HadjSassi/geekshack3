package doWhileLoops;

import java.util.Scanner;

public class Ex3 {

    public static void main(String[] args) {
        Scanner key = new Scanner(System.in);
        int height = 0, noBounces = 0, fivePer = 0;
        fivePer = height /100 * 5;
        System.out.print("\n\tEnter the height in feet that the ball will be dropped from: ");
        height = key.nextInt();
        do {
            System.out.print("\n\tIt took  " + (height - fivePer));
            fivePer--;
        } while (height > 0);
    }
}