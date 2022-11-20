#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
typedef vector<pair<int,int>> vii;

bool notdigit(char c){
    return !(c >= '0' && c <='9');
}
char grid[15][15];
int dis[15][15];
int dirs[8][2] {{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
int main() {
    memset(grid,'.',sizeof grid);
    int l,c,gx,gy,px,py;
    string s;
    for(int i = 0;i<15;i++)for(int j = 0;j<15;j++)dis[i][j] = INT_MAX - 1000000;
    getline(cin,s);
    stringstream geek(s);
    for(char ch : s){
        if(ch != ' ' && notdigit(ch)){
            cout << "INPUT_ERROR" << endl;
            return 0;
        }
    }
    geek >> l >> c;
    getline(cin,s);
    for(char ch : s){
        if(ch != ' ' && notdigit(ch)){
            cout << "INPUT_ERROR" << endl;
            return 0;
        }
    }
    stringstream geek0(s);
    geek0>> gx >> gy >> px >> py;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        char cx , cy;
        cin >> cx >> cy;
        if(notdigit(cx) || notdigit(cy)){
            cout << "INPUT_ERROR" << endl;
            return 0;
        }
        int x = (int)(cx - '0'), y = (int)(cy - '0');
        grid[x][y] = '#';
    }

    queue<pair<int,int>> bfs;
    bfs.push({gx,gy});
    dis[gx][gy] = 0;

    while(bfs.size()){
        int x = bfs.front().first;
        int y = bfs.front().second;
        int dis0 = dis[x][y];
        if(x == px && y == py){
            cout << dis0 << endl;
            return 0;
        }
        bfs.pop();
        for(auto p : dirs){
            int x0 = x + p[0];
            int y0 = y + p[1];
            int newdis = dis0 + 1;
            if(x0 < 0 || y0 < 0 || x0 == l || y0 == c || grid[x0][y0] == '#' || dis[x0][y0] <= newdis)continue;
            dis[x0][y0] = newdis;
            bfs.push({x0,y0});
        }
    }
    cout << 0 << endl;
}
