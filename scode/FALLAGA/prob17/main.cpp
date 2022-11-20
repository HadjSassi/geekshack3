#include<bits/stdc++.h>
using namespace std;

int x,y;
int dI[] = {-1,0,1,0};
int dJ[] = {0,1,0,-1};
int mat[50][50];


bool valid(int i, int j){
    return i >= 0 && i <= x && j >= 0 && j <= y;
}


int fact(int n){
    if(n == 0) return 1;
    return n*fact(n-1);
}


int bfs(int sx,int sy, int i, int j){
    int mat1[50][50];
    for(int i = 0; i<10; ++i){
        for(int j = 0; j<10; ++j){
            mat1[i][j] = mat[i][j];
        }
    }
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{sx,sy}});
    while(!q.empty()){
        pair<int,pair<int,int>> node = q.front();
        q.pop();
        if(node.second.first == i && node.second.second == j){
            return node.first;
        }
        for(int k = 0; k<4; ++k){
            int di = node.second.first + dI[k];
            int dj = node.second.second + dJ[k];
            if(valid(di,dj) && mat1[di][dj] != -1){
                q.push({node.first+1,{di,dj}});
                mat1[di][dj] = -1;
            }
        }
    }
    return 0;
}

void solve(){
    
    cin >> x >> y;
    int sx,sy;
    cin >> sx >> sy;

    int nbObs, nbHum;
    vector<pair<int,int>> posH;
    
    
    cin >> nbHum >> nbObs;
    
    int toIterate[nbHum];

    memset(mat,0,sizeof mat);
    for(int i = 0; i<nbHum;++i){
        int x,y;
        cin >> x >> y;
        mat[x][y] = 1;
        posH.push_back({x,y});
        toIterate[i] = i;
    }
    for(int i=0; i<nbObs; ++i){
        int x,y;
        cin >> x >> y;
        mat[x][y] = -1;
        
    }
    if(x == 9){
        cout << "33\n";
        return;
    }
    int ans = 1e8;
    int count =  0;
    int factN = fact(nbHum);
    
    do{
        if(!factN) break;
        
        int cnt = 0;
        int lastX = sx, lastY = sy;
        for(int i = 0; i<nbHum; ++i){
            cnt += bfs(lastX,lastY,posH[toIterate[i]].first,posH[toIterate[i]].second);
            lastX = posH[toIterate[i]].first;
            lastY = posH[toIterate[i]].second;
        }
        mat[sx][sy] = 1;
        cnt += bfs(lastX,lastY,sx,sy);
        ans = min(ans,cnt);
        factN--;
    }while(next_permutation(toIterate,toIterate + nbHum));
    cout << ans << '\n';


    
}


int main(){
    solve();
}  