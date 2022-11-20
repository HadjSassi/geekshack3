import java.util.ArrayList;
import java.util.Scanner;

// A Dynamic Programming based solution for 0-1 Knapsack problem
class Main
{

    // A utility function that returns maximum of two integers
    static int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
    static int knapSack(int W, Integer[] wl1, Integer[] val1, int n)
    {
        int i, w;
    int K[][] = new int[n+1][W+1];
            int[] selected = new int[n + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0){
                //selected[i] = 1;
                K[i][w] = 0;
            }
            else if (wl1[i-1] <= w){
                selected[i] = 1;
                K[i][w] = max(val1[i-1] + K[i-1][w-wl1[i-1]], K[i-1][w]);
            }
            else{
                selected[i]=0;
                K[i][w] = K[i-1][w];
            }
        }
    }
    int tempW = W;
    int y = 0; //to index in selected
    for (int x = n; x > 0; x--){
        if ((tempW-wl1[x-1] >= 0) && (K[x][tempW] - K[x-1][tempW-wl1[x-1]] == val1[x-1]) ){
            selected[y++] = x-1; //store current index and increment y
            tempW-=wl1[x-1];
        }
     }
     for(int j = y-1; j >= 0; j--){
         if(j!=0){
        System.out.print((char)((selected[j]+1)+'A'-1)+" ");
    }
         else{System.out.print((char)((selected[j]+1)+'A'-1)+"");
}
     }
    System.out.println("");
    return K[n][W];
    }


    // Driver program to test above function
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int W = sc.nextInt();
        int max=sc.nextInt();
        ArrayList<Integer> val = new ArrayList<Integer>();
        ArrayList<Integer> wl = new ArrayList<Integer>();
    for(int i=0;i<max+1;i++){
        String S=sc.nextLine();
        if(i>=1){
        val.add((int) (S.charAt(2)-'0'));
        wl.add((int) (S.charAt(4)-'0'));
    }
}


    
    

    int n = val.size();
    Integer [] val1 = new Integer[n];
    Integer[] wl1 = new Integer [n];
    val1=val.toArray(val1);
    wl1=wl.toArray(wl1);
    System.out.println(knapSack(W, val1, wl1, n));
    }
}