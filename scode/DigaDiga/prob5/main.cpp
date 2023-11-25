/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
//#ifndef ONLINE_JUDGE
//#include "debug.cpp"
//#else
//#define kar(...)
//#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int  N=2e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

void Solve(){
    int l , r , ans= 0;
    cin >> l >> r ;
    for (int len = 2; len<=61; len++){
        int mask = (1ll<<len)-1;
        for (int i= 0; i<len-1 ;i++){
            int ver = mask ^(1ll<<i) ;
            ans+=(ver <= r && ver >= l);
        }
    }
    cout << ans << endl;
}

int32_t main(){
//    #ifndef ONLINE_JUDGE
//        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
//        freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
//    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}