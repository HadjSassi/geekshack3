#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
typedef vector<pair<int,int>> vii;

char grid[30][30];
int diss[30][30];
int dirs[4][2] {{-1,0} , {0,-1} , {1,0} , {0,1}};
int dp[11][11][11][11];
int distance(int x0, int y0,int x1,int y1){
    if(dp[x0][y0][x1][y1] != -1)return dp[x0][y0][x1][y1];
    for(int i = 0;i<30;i++)for(int j = 0;j<30;j++){
        diss[i][j] = INT_MAX - 100000;
    }

    queue<pair<int,int>> bfs;
    bfs.push({x0,y0});
    diss[x0][y0] = 0;
    while(bfs.size()){
        int x = bfs.front().first;
        int y=  bfs.front().second;
        bfs.pop();
        if(x == x1 && y1 == y){
            return dp[x0][y0][x1][y1] = diss[x][y];
        }
        for(auto p : dirs){
            int x2 = x + p[0];
            int y2 = y + p[1];
            if(x2 < 0 || y2 < 0 || grid[x2][y2] == '#' || diss[x2][y2] <= (diss[x][y] + 1))continue;
            bfs.push({x2,y2});
            diss[x2][y2] = diss[x][y] + 1;
        }
    }
    return INT_MAX-100000;
}
int main() {
    memset(grid,'.',sizeof grid);
    memset(dp,-1,sizeof dp);
    int p1,p2;
    cin >> p1 >>  p2;
    p1++;p2++;
    for(int i = 0;i<p1;i++)
        for(int j = 0;j<p2;j++)grid[i][j] = '.';
    int x , y;
    cin >> x >> y;
    int n,o;
    cin >> n >> o;
    vii a,obs;
    for(int i = 0;i<n;i++){
        int b,c;
        cin >> b >> c;
        a.push_back({b,c});
    }
    for(int i = 0;i<o;i++){
        int b,c;
        cin >> b >> c;
        obs.push_back({b,c});
        grid[b][c] = '#';
    }

    vector<int> try0;
    for(int i = 0;i<n;i++){
        try0.push_back(i);
    }
    int res = INT_MAX;
    do{
        int m = 0,lastX = x,lastY = y;
       // if(p1 == p2 && p1 == 10) m = -1;
        for(int i :try0){
            m += distance(lastX,lastY,a[i].first,a[i].second);
            lastX = a[i].first;
            lastY = a[i].second;
        }
        m += distance(lastX,lastY,x,y);
        res = min(res, m);
    }while (next_permutation(try0.begin(),try0.end()));
    cout << res << endl;
}       