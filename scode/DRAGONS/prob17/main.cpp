#include <bits/stdc++.h>
#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define ROW 11
#define COL 11
int graph[11][11];
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
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

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

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            if (isValid(row, col) && graph[row][col]!=2
                    )

            {

                graph[row][col]=2;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }
    return 0;
}

int main()
{

    bool tst=false;
    cin>>n>>m;
    memset(graph,0, sizeof(graph));
    int dx,dy,nbP,nbO;
    cin>>dx>>dy;
    cin>>nbP>>nbO;

    for (int i=0 ; i<nbP ; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
    }
    for(int i=0;i<nbO;i++){
        int a,b;
        graph[a][b]=2;
    }

    Point source = {dx, dy};
    Point dest;

    //int dist =BFS(source,dest);
    int d=0;
    int l1,l2;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(graph[i][j]==1){
                dest = {i,j};
                d+=BFS(source, dest);
                source=dest;
                l1=i;l2=j;
                }
        }
        }
    memset(graph,0, sizeof(graph));
    source={l1,l2};
    //cout<<l1<<l2;
    //cout<<BFS({9,4},{dx,dy});
     dest = {dx, dy};
    d+=BFS(source,dest);
   if (d != -1)
       cout << d;
    else
        cout << 0;
    //}
    return 0;
}     