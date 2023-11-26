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

const int  N=6e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;


void Solve(){
    int n;
    cin >> n ;
    vector <int> v(n) ;
    vector <int> curr ;
    for (int i= 0; i<2*n ;i++){

        cin >> v[i] ;
        if (i<n) curr.pb(i+1);
    }
    swap(curr[0],curr[1]);
    for (int i=0 ; i<n ; i++){
        cout << curr[i] << "  " << curr [i] <<" "  ;
    }cout << endl;
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