import java.util.* ;
public class Main {
    public static void main(String args[]) {
        
        Scanner sc = new Scanner(System.in) ;
        int n =sc.nextInt() ;
        int t [];
        int matrice[][];
        for(int i=0;i<matrice.length;i++){
              for(int j=0;j<matrice[i].length;j++){
                    matrice[i][j] =sc.nextInt() ;
              } 
        }
        int k=0;
        while(k<(n-matrice.length)){
                for(int h=0;h<t.length;h++){
                     t[h] =sc.nextInt() ;
              } 
              
                  
           int m=0;
            while(m< matrice.length){
                if (Arrays.equals(matrice[m], t)  )   
                  {          System.out.println(t);
                         break;
                  }
                  else{ m++;}
               
        }
        
        
       

    }
}}   