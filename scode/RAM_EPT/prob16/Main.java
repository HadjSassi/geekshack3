// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;






// Please name your class Main
public class Main {
    static Scanner in = new Scanner(System.in);
    public static void main (String[] args) throws java.lang.Exception {
        PrintWriter out = new PrintWriter(System.out);



        int T=Int();
        for(int t=0;t<T;t++){
            int n=Int();int m=Int();
            int A[][]=new int[m][2];

            for(int i=0;i<A.length;i++){
                A[i][0]=Int()-1;
                A[i][1]=Int()-1;
            }

            Solution sol=new Solution();
            sol.solution(out,n,A);
        }
        out.flush();

    }

    public static long Long(){ return in.nextLong();}
    public static int Int(){
        return in.nextInt();
    }
    public static String Str(){
        return in.next();
    }
}



class Solution{
    List<Integer>g[];
    int res[];
    int dis[];
    boolean visit[];
    public void solution(PrintWriter out,int n,int A[][]){

        dis=new int[n];
        visit=new boolean[n];
        res=new int[n];
        Arrays.fill(dis,Integer.MAX_VALUE);
        g=new ArrayList[n];
        for(int i=0;i<n;i++){
            g[i]=new ArrayList<>();
        }

        for(int p[]:A){
            int v1=p[0],v2=p[1];
            g[v1].add(v2);
        }

        //run bfs
        Queue<Integer>q=new LinkedList<>();
        q.add(0);dis[0]=0;visit[0]=true;res[0]=0;
        while(q.size()!=0){
            int r=q.poll();
            List<Integer>list=g[r];
            for(int next:list){
                if(!visit[next]){
                    visit[next]=true;
                    dis[next]=1+dis[r];
                    res[next]=dis[next];
                    q.add(next);
                }
            }
        }

        Arrays.fill(visit,false);


        for(int i=0;i<n;i++){
            if(!visit[i]){
                visit[i]=true;
                dfs(i);
            }
        }



        for(int i:res){
            out.print(i+" ");
        }
        out.println();
    }

    public int dfs(int root){
        List<Integer>list=g[root];
        int d=dis[root];
        for(int next:list){
            d=Math.min(d,dis[next]);
            if(visit[next]){
                if(dis[root]<dis[next]){
                    d=Math.min(d,res[next]);
                }
                else{

                }
            }
            else{
                if(dis[root]>=dis[next]){

                }
                else{
                    visit[next]=true;
                    int val=dfs(next);
                    d=Math.min(d,val);
                }
            }
        }
        res[root]=d;
        return d;
    }

    public void print(int A[]){
        for(int i:A){
            System.out.print(i+" ");
        }System.out.println();
    }


}
