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
    int n, ans = 0;
    cin >> n;
    vector <int> v(n) ;
    for (auto &x: v) cin >> x;
    for (int i= 1 ;i<(1ll<<n); i++){
        int gcd= -1 , cnt= 0;
        for (int j= 0; j<n; j++){
            if (!((1ll<<j)&i)) continue;
            if (gcd == -1) gcd =v[j] ;
            cnt ++ ;
            gcd = __gcd (gcd , v[j]);
        }
        if (gcd !=1 ) {
            ans += cnt * gcd %mod;
            ans %= mod ;
        }
    }
    cout << ans << endl;
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