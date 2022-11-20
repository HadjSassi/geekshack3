//#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define ROW 5
#define COL 5
int graph[5][5];
int n,m;
struct Point
{
    int x;
    int y;
};
struct queueNode
{
    Point pt;
    int dist;
};
bool isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}
int rowNum[] = {-1, 0, 0, 1,-1,-1,1,1};
int colNum[] = {0, -1, 1, 0,-1,1,1,-1};

int BFS( Point src, Point dest)
{
    queue<queueNode> q;

    queueNode s = {src, 0};
    q.push(s);
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;

        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            if (isValid(row, col) && graph[row][col]==0
                )

            {

                graph[row][col]=1;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }
    return -1;
}

int main()
{
    bool tst=false;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            graph[i][j]=0;
    }
    int gx,gy,px,py,k;
    cin>>gx>>gy>>px>>py;
    cin>>k;
    for (int i=0 ; i<k ; i++)
    {
        char a,b;
        cin>>a>>b;
        if(a>='a') {
            cout <<"INPUT_ERROR";
            //tst=true;
            return(0);
        }
        graph[a-'0'][b-'0']=1;
    }

    Point source = {gx, gy};
    Point dest = {px, py};
    //if(tst==true) {
      //  cout <<"INPUT_ERROR";
        //return 0;
    //}
    //else {
       int dist = BFS(source, dest);

        if (dist != -1)
            cout << dist;
        else
            cout << 0;
    //}
    return 0;
}
