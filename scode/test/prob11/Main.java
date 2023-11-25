import java.util.Scanner;
class Main {
    public static void main(String[] args) {
        

        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int count = 0;

        for (int i = 0; i < 65; i++) {
            for (int j = 0; j < i - 1; j++) {
                int value = (int) (Math.pow(2, i) - 1) - (int) Math.pow(2, j);
                if (a <= value && value <= b) {
                    count++;
                }
            }
        }
        System.out.println(count);
        scanner.close();
 
    }
} 