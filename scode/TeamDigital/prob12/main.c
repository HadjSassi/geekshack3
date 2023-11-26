#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
typedef long long ll;
const double Pi = acos(-1.0);
const int N = 1e6+10, M = 1e3+20, mod = 1e9+7, inf = 2e9+10; 
const double e=2.718281828459;
const double esp=1e-9;
using namespace std;
int n,m;
char maze[M][M];
int vis[M][M];
struct node
{
int x,y;
int step;
};
void bfs()
{
memset(vis,0, sizeof(vis));
queue<node>q;
node a,b;
a.x=0;
a.y=0;
a.step=0;
vis[a.x][a.y]=1;
q.push(a);
while(!q.empty())
{
a=q.front();
q.pop();
int mm=maze[a.x] [a.y]-'0';
if(a.x==n-1&&a.y==m-1)
{
printf("%d\n",a.step); return;
}
for(int i=0;i<4;i++)
{
int xx,yy;
if(i==0)
{xx=a.x-mm; yy=a.y; }
else if(i==1)
{xx=a.x; yy=a.y+mm; }
else if(i==2)
{ xx=a.x+mm;yy=a.y;}
else
{xx=a.x;yy=a.y-mm;}
if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]==0)
{
b.x=xx; b.y=yy; vis[xx][yy]=1; b.step-a.step+1; q.push(b);
}
}
}
printf("-1\n");
}
int main()
{
while(~scanf("%d%d", &n,&m))
{
for(int i=0;i<n;i++)
{
scanf("%s",maze[i]);
}
bfs();
}
return 0;
}