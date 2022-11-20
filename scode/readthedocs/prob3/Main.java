import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
    
    Scanner sc=new Scanner(System.in);
    int t=sc.nextInt();
    String x = Integer.toBinaryString(t);
    int n=x.length();
    int[] T = new int[10];
    for(int i=0;i<n;i++){
        T[i]=x.charAt(i)-'0';
    }

    for(int j=0;j<n;j++){
        if(T[j]==1){
            T[j]=(int) (T[j]* Math.pow(10,n-j-1));
        }
    }
    for(int k=0;k<n;k++){
        if(T[k]==1){System.out.println("take_position");}
        if(T[k]==10){System.out.println("run");}
        if(T[k]==100){System.out.println("need_backup");}
        if(T[k]==1000){System.out.println("declare_your_position");}

        
    }
    }

    
}
