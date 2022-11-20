import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
    
    Scanner sc=new Scanner(System.in);
    String l=sc.nextLine();
    if((int)l.charAt(0)-'0'>0){System.out.println("NOT_CLEAR");}
    else{
    int t=(int)l.charAt(0)-'0';
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
    String S="";
    for(int k=0;k<n;k++){
        if(T[k]==1){S= S+("take_position ");}
        if(T[k]==10){S=S+("run ");}
        if(T[k]==100){S=S+("need_backup ");}
        if(T[k]==1000){S =S+("declare_your_position ");}

        
    }
    S=S.strip();
    System.out.println(S);
    }
}

    }

    
}
  