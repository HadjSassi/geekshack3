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
    int n ;
    char  c;
    string s ;
    cin >> n >> c >> s ;
    vector <int> divisors;
    for (int i= 1; i*i <= n  ; i++){
        if (n%i) continue;
        divisors.pb(i);
        if (n/i==i) continue;
        divisors.pb(n/i);
    }
    if (c=='D')sort (all(divisors));
    else sort (rall(divisors));
    for (auto d : divisors){
        string nw = "" ;
        for (int i=0 ;i<n ;i++){
            nw+= s[i];
            if (i==d-1)reverse(all(nw));
        }
        s= nw ;
    }
    cout << s << endl;
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