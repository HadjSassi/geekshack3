#include<bits/stdc++.h>
using namespace std;
int t[100][100] ;
int vis[100][100] ;
int dI[] = {-1,0,1,0};
int dJ[] = {0,1,0,-1};

int valid(int i, int j){
    return i >=0 && i < 10 && j >= 0 && j < 10;
}

void dfs(int i, int j, int& x){
    x++;
    t[i][j] = 0;
    for(int k = 0; k<4; k++){
        int di = i + dI[k];
        int dj = j + dJ[k];
        if(valid(di,dj) && t[di][dj]){
            dfs(di,dj,x);
        }
    }
}

vector<int> tot ;
void solve(){
    int  n,k ;
    while(cin >> n){
    string s;
    int i = 0 ;
    cin.ignore() ;
    while( getline(cin,s) ){
        stringstream intValue(s);
         while(intValue >> k){
           // cout << k <<"    ";
            t[i][k] = 1 ;
         }

        i++ ;
        if(i == n) break ;
    }



    vector<int> ans;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<10; ++j){
            if(t[i][j]){
                int x = 0;
                dfs(i,j,x);
                ans.push_back(x);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(int i = 0; i<ans.size(); ++i){
        cout << ans[i]*100 << '\n';
    }
    return;
}
    cout << "NO";

}

int main(){
    solve();
}


