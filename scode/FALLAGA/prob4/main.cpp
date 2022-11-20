#include<bits/stdc++.h>
using namespace std;
int t[100][100] ;
int vis[100][100] ;
int dI[] = {-1,0,1,0};
int dJ[] = {0,1,0,-1};

int valid(int i, int j){
    return i >=0 && i < 10 && j >= 0 && j < 10;
}

void dfs(int i, int j, int& x,int val){
    x++;
    t[i][j] = 0;
    for(int k = 0; k<4; k++){
        int di = i + dI[k];
        int dj = j + dJ[k];
        if(valid(di,dj) && t[di][dj] == val){
            dfs(di,dj,x,val);
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
    int c = 0;
    for(int i = 0; i<n; ++i){
        getline(cin,s);
        c = 0;
        for(int j=0; j<s.length(); ++j){
            if(s[j] == ' ' ) continue;
            if(s[j] == 'S') t[i][c] = 1;
            else if(s[j] == 'T') t[i][c] = 2;
            c++;
        }
    }



    vector<vector<int>> ans(2);
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<10; ++j){
            if(t[i][j] == 1){
                int x = 0;
                dfs(i,j,x,1);
                ans[0].push_back(x);
            }
        }
    }



    for(int i = 0; i<n; ++i){
        for(int j = 0; j<10; ++j){
            if(t[i][j] == 2){
                int x = 0;
                dfs(i,j,x,2);
                ans[1].push_back(x);
            }
        }
    }
    sort(ans[0].begin(),ans[0].end());
    sort(ans[1].begin(),ans[1].end());
    cout << "S ";
    for(int i = 0; i<ans[0].size(); ++i){
        cout << ans[0][i]*100;
        if(i < ans[0].size() - 1) cout << ' ';
    }
    cout << "\nT ";

    for(int i = 0; i<ans[1].size(); ++i){
        cout << ans[1][i]*100;
        if(i < ans[1].size() - 1) cout << ' ';
    }

    return;
}
    cout << "NO";

}

int main(){
    solve();
}


