/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
typedef long long ll;
using namespace std;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'
int n , m ;

const int  N=6e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;
char t[10][10] ;

int ok (int i, int j){
    if (j+3 <m && t[i][j]==t[i][j+1]&&t[i][j]==t[i][j+2]&&
        t[i][j]==t[i][j+3]&& t[i][j]!='0')return t[i][j]-'0';
    if (i+3 <n && t[i][j]==t[i+1][j]&&t[i][j]==t[i+2][j]&&
        t[i][j]==t[i+3][j]&& t[i][j]!='0')return t[i][j]-'0';
    if (i+3 <n &&j+3 <m && t[i][j]==t[i+1][j+1]&&t[i][j]==t[i+2][j+2]&&
        t[i][j]==t[i+3][j+3]&& t[i][j]!='0')return t[i][j]-'0';
    if (i-3 >=0 &&j+3 <m && t[i][j]==t[i-1][j+1]&&t[i][j]==t[i-2][j+2]&&
        t[i][j]==t[i-3][j+3]&& t[i][j]!='0')return t[i][j]-'0';
    return 0 ;
}

void Solve(){
    cin >> n >> m ;
    int one =0 , two = 0;
    for (int i= 0 ; i<n ; i++){
        for (int j= 0; j<m; j++){
            cin>>t[i][j];
            if (t[i][j]=='1')one ++ ;
            if (t[i][j]=='2') two ++ ;
        }
    }
    for (int i= 0 ; i<n ; i++){
        for (int j= 0; j<m; j++) {
            if (ok(i,j)) {cout << t[i][j] ; return;}
        }
    }
    for (int i= 0; i<n; i++){
        for (int j= 0 ; j<m ; j++){

            if (i==n-1 && t[i][j] == '0' || t[i][j]=='0' && t[i+1][j]!='0'){
                if (one>two) t[i][j]='2';
                else t[i][j]='1';
                for (int a= 0 ; a<n ; a++){
                    for (int b= 0; b<m; b++) {
                        if (ok(a,b)) {cout << t[a][b] ; return;}
                    }
                }
                t[i][j]='0' ;
            }
        }
    }
    cout << '0' << endl;
}

int32_t main(){
//     #ifndef ONLINE_JUDGE
//         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
//         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
//     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
} 