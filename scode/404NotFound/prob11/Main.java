import java.util.Scanner;
class Main
{
    public static void main(String args[])
    {
      Scanner sc = new Scanner(System.in);
      System.out.print("Entrez un nombre decimal : ");
    
      int nbr = sc.nextInt();
      String str = Integer.toBinaryString(nbr);
      System.out.println("Le nombre binaire est : "+str);
    }
}