

#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
#define pdd pair<double,double>

int grid[1005][1005];
int n,m;

bool check(int x,int y,int t){
    bool v1=1,v2=1,v3=1;
    for(int i = 0;i<4;i++){
        if(grid[x+i][y] != t)v1 =0;
        if(grid[x][y+i] != t)v2 =0;
        if(grid[x+i][y+i] != t)v3 =0;
    }
    bool v4 = 0;
    if(x>=3){
        v4 = 1;
        for(int i = 0;i<4;i++){
            if(grid[x-i][y+i] != t)v4 = 0;
        }
    }
    return v1 | v2 | v3 | v4;
}
int check0(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(check(i,j,1)){
                return 1;
            }
            if(check(i,j,2)){
                return 2;
            }
        }
    }
    return 0;
}
int main(){
    cin >> n >> m;
    map<int,int> c0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)cin >> grid[i][j];
    }


    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            c0[grid[i][j]]++;
            if(check(i,j,1)){
                cout << 1 << endl;
                return 0;
            }
            if(check(i,j,2)){
                cout << 2 << endl;
                return 0;
            }
        }
    }
    cerr << "hi" << endl;
    int turn = 2;
    if(c0[1] == c0[2])turn = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] != 0)continue;
            if(i == 0 || grid[i-1][j] != '0'){
                grid[i][j] = turn;
                int res = check0();
                grid[i][j] = 0;
                if(res == 0)continue;
                cout << res << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
} 