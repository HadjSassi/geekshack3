/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int  N=1e5+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

int dp[N] ;

void Solve(){
    int n , z ;
    cin >> n >> z;
    vector <int> s;
    vector <array<int,2>> vp(n) ;
    for (int i= 0;i<n ;i++) cin >> vp[i][0] >> vp[i][1] ;
    s.push_back(0);
    for (int i= 0; i<n; i++){
    	vector<int> v;
        for (int curr : s ){
            if (curr +2 <N ) {
                if (!dp[curr+2]) {
                    dp[curr + 2] = dp[curr] + vp[i][1];
                    v.pb (curr +2 );
                }
                dp[curr+2]= min (dp[curr+2], dp[curr]+vp[i][1] );
            }
            if (curr +1 < N ){
                if (!dp[curr+1]) {
                    dp[curr+1]= dp[curr]+vp[i][0];
                    v.pb (curr +1 );
                }
                dp[curr+1]= min (dp[curr+1], dp[curr]+vp[i][0] );
            }
        }
        for (int x : v) s.pb(x);
    }
    int ans = 1e18 ;
    for (int curr : s){
        if (curr >= z){
        	assert(curr < N);
            ans = min (ans , dp[curr]);
        }
    }
    cout << ans << endl;
}

int32_t main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
    //     freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
    // #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
} 