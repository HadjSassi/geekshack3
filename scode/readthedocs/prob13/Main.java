import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
     
    private static int max(int i, int j)
    {
            return (i > j) ? i : j;
    }
     
    // Returns the maximum value with knapsack
    // of W capacity
    private static int unboundedKnapsack(int W, int n,
                                Integer[] val, Integer[] wt)
    {
         
        // dp[i] is going to store maximum value
        // with knapsack capacity i.
        int dp[] = new int[W + 1];
         
        // Fill dp[] using above recursive formula
        for(int i = 0; i <= W; i++){
            for(int j = 0; j < n; j++){
                if(wt[j] <= i){
                    dp[i] = max(dp[i], dp[i - wt[j]] +
                                val[j]);
                }
            }
        }
        return dp[W];
    }
 
    // Driver program
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
        val.add((int) (S.charAt(0)-'0')*10 + S.charAt(1)-'0');
        wl.add((int) (S.charAt(3)-'0')*10 + S.charAt(4)-'0');
    }
}

    int n = val.size();
    Integer [] val1 = new Integer[n];
    Integer[] wl1 = new Integer [n];
    val1=val.toArray(val1);
    wl1=wl.toArray(wl1);
    System.out.println(unboundedKnapsack(W, n, wl1, val1));
}
} 