import java.util.*;
import java.io.*;
import java.lang.Math;
public class Main {
  public static void main(String args[]) throws IOException {
    Scanner sc= new Scanner(System.in);
    int test = sc.nextInt();
      while(test != 0){
        String a = sc.next();
        int no_of_operations = 0;
        for(int i=0; i<a.length()/2; i++){
          no_of_operations += Math.abs( a.charAt(a.length()-i-1) - a.charAt(i) );
        }
        System.out.println(no_of_operations);
        test--;
      }
  }
} 