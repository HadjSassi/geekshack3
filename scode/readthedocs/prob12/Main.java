
import java.util.*;

class QItem {
  int row;
  int col;
  int dist;
  public QItem(int row, int col, int dist)
  {
    this.row = row;
    this.col = col;
    this.dist = dist;
  }
}
 
public class Main{
  private static int minDistance(char[][] grid)
  {
    QItem source = new QItem(0, 0, 0);
     

    firstLoop:
    for (int i = 0; i < grid.length; i++) {
      for (int j = 0; j < grid[i].length; j++)
      {
         

        if (grid[i][j] == 's') {
          source.row = i;
          source.col = j;
          break firstLoop;
        }
      }
    }
     

    Queue<QItem> queue = new LinkedList<>();
    queue.add(new QItem(source.row, source.col, 0));
 
    boolean[][] visited
      = new boolean[grid.length][grid[0].length];
    visited[source.row][source.col] = true;
 
    while (queue.isEmpty() == false) {
      QItem p = queue.remove();
       
      if (grid[p.row][p.col] == 'd')
        return p.dist;
 
 
      if (isValid(p.row - 1, p.col, grid, visited)) {
        queue.add(new QItem(p.row - 1, p.col,
                            p.dist + 1));
        visited[p.row - 1][p.col] = true;
      }
      if (isValid(p.row + 1, p.col, grid, visited)) {
        queue.add(new QItem(p.row + 1, p.col,
                            p.dist + 1));
        visited[p.row + 1][p.col] = true;
      }
 

      if (isValid(p.row, p.col - 1, grid, visited)) {
        queue.add(new QItem(p.row, p.col - 1,
                            p.dist + 1));
        visited[p.row][p.col - 1] = true;
      }
 
      if (isValid(p.row - 1, p.col + 1, grid,
                  visited)) {
        queue.add(new QItem(p.row, p.col + 1,
                            p.dist + 1));
        visited[p.row][p.col + 1] = true;
      }
    }
    return -1;
  }
  private static boolean isValid(int x, int y,
                                 char[][] grid,
                                 boolean[][] visited)
  {
    if (x >= 0 && y >= 0 && x < grid.length
        && y < grid[0].length && grid[x][y] != '*'
        && visited[x][y] == false) {
      return true;
    }
    return false;
  }
   
  public static void main(String[] args)
  {
    Scanner t=new Scanner(System.in);
    int x=t.nextInt();
    int y=t.nextInt();
    int sx=t.nextInt();
    int sy=t.nextInt();
    int dx=t.nextInt();
    int dy=t.nextInt();
    char[][] grid=new char[x][y];
    grid[sx][sy]='s';
    grid[dx][dy]='d';
    int nombre=t.nextInt();

    while(nombre>0){
        nombre--;
        int x1=t.nextInt();
        int y1=t.nextInt();
        grid[x1][y1]='*';
    }
 
    int M= (minDistance(grid));
    int M1=M/2;
    int M2=M-M1;
    int n =(int) Math.sqrt(M1*M1+M2*M2);
    System.out.println(n);
}
}