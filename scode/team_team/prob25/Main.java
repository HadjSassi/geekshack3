import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
    public static class BIT{ // 注: 1-index
    int[] bit;
    public BIT(int n){
        this.bit=new int[n];
    }
    public int lowbit(int x){
        return x&(-x);
    }
    public void update(int index,int val){
        while(index<bit.length){
            bit[index]+=val;
            index+=lowbit(index);
        }
    }
    public int query(int index){ // sum of [1,index]
        int sum=0;
        while(index>0){
            sum+=bit[index];
            index-=lowbit(index);
        }
        return sum;
    }
}

    //static int[][] dir={{0,1},{0,-1},{1,0},{-1,0}};
    //static Map<Integer,Integer> mp=new HashMap<>();
    //static Map<Integer,List<Integer>> mp=new HashMap<>();
    //static Map<Integer,List<int[]>> mp=new HashMap<>();
    //static List<int[]> ls=new ArrayList<>();
    //static List<Integer> ls=new ArrayList<>();
    //static PriorityQueue<Integer> pq=new PriorityQueue<>();
    //static Deque<Integer> d=new ArrayDeque<>();
    //static Set<Integer> set=new HashSet<>();
    //static StringBuilder sb=new StringBuilder();
    static BufferedReader infile;
    static StringTokenizer st;
     public static void main(String []args) throws Exception
     {  
		solve();
     }
     public static void solve() throws Exception{
        infile = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(infile.readLine());
        int n=Integer.parseInt(st.nextToken());
	    int[] arr=new int[n+1];
        st = new StringTokenizer(infile.readLine());
        for(int i=1;i<=n;i++) arr[i]=Integer.parseInt(st.nextToken());
        Map<Integer,Integer> r=new HashMap<>();
        for(int i=n;i>=1;i--) if(!r.containsKey(arr[i])) r.put(arr[i],i);
        Set<Integer> set=new HashSet<>();
        long ans=0;
        BIT bit=new BIT(n+1);
        for(int i=1;i<=n;i++){
            if(set.contains(arr[i])) continue;
            set.add(arr[i]);
            ans+=(r.get(arr[i])-i-1);
            ans-=bit.query(r.get(arr[i]))-bit.query(i);
            bit.update(r.get(arr[i]),1);
        }
        System.out.println(ans);
        
     }
}