#include <bits/stdc++.h>

using namespace std;

#define s second
#define f first
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef pair<int,pii> piii;

string grid[1005];
vector<vector<int>> dis;
int dirs[4][2] = {{0,1} , {1,0} , {-1,0} , {0,-1}};
int jump[1005][1005][4];
bool v[1005][1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(jump,-1,sizeof jump);
    int h,w,k;
    cin >> h >> w >> k;
    dis = vector<vector<int>>(h,vector<int>(w,1e9));
    int sx,sy,fx,fy;
    cin >> sx >> sy >> fx >> fy;
    sx--;sy--;fx--;fy--;
    for(int i = 0;i<h;i++)cin >> grid[i];

    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({0,{sx,sy}});
    dis[sx][sy] = 0;

    while(pq.size()){
        auto p = pq.top();
        int x = p.s.f,y = p.s.s, d = p.f;
        pq.pop();
        if(v[x][y])continue;
        v[x][y] = 1;
        if(x == fx && y == fy)break;
        for(int o = 0;o<4;o++){
            auto p1 = dirs[o];
            int j = -1;
            vector<pii> l;
            for(int i = 1;i<=k;i++) {

                int x0 = x + i * p1[0];
                int y0 = y + i * p1[1];
                if (x0 < 0 || y0 < 0 || x0 == h || y0 == w || grid[x0][y0] == 'X')break;
                if(v[x0][y0]){
                    if(dis[x0][y0] < d)break;
                    if(jump[x0][y0][o] != -1)i += jump[x0][y0][o];
                    continue;
                }
                if(jump[x0][y0][o] != -1)i += jump[x0][y0][o];
                if(dis[x0][y0] <= d)continue;

                j = i;
                l.push_back({x0,y0});
                pq.push({d+1,{x0,y0}});
                dis[x0][y0] = d + 1;
            }
            if(j == -1)continue;
            for(auto p2 : l){
                jump[p2.f][p2.s][o] = j - abs(p2.s - y) - abs(p2.f - x) - 1;
            }

        }
    }

    cout << dis[fx][fy] << endl;
}


