#include <bits/stdc++.h>

using namespace std;



#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define inf 1000000000
#define sz(x) (ll)x.size()
#define boost() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair< int , pii> piii;
typedef pair<int,bool> pib;
typedef vector<pii> vii;
typedef vector<pib> vib;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<string,string> pss;
typedef pair<ll , ll> pll;
typedef vector<pss> vss;
typedef pair<ld , ld> pdd;
typedef vector<ld> vd;
typedef vector<vector<pib>> vvib;
typedef vector<piii> viii;
typedef vector<viii> vviii;
typedef vector<bool> vb;
typedef pair<pii , bool> piib;
typedef vector<pair<pii , bool>> viib;
const int   MOD = 1e9 + 7; //998244353;
const int N = 500005;


int main() {
    short dp[10][15];
    char c[10];
    short w[10],p[10];
    vector<char> map0[10][15];
    short h,n;
    cin >> h >> n;

    for(int i = 0;i<n;i++)cin >> c[i] >> w[i] >> p[i];
    for(int i = 0;i<=n;i++){
        ;
        for(int j = 0;j<=h;j++){
            dp[i][j] = -1;
            if(i == 0){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            if(j - w[i-1] >= 0){
                short res = dp[i-1][j - w[i-1]] + p[i-1];
                if(res > dp[i][j]){
                    dp[i][j] = res;
                    for(char ca : map0[i-1][j - w[i-1]]){
                            map0[i][j].pb(ca);

                        }
                    map0[i][j].pb(c[i-1]);
                }
                else {

                    for(char ca : map0[i-1][j]){
                        map0[i][j].pb(ca);
                    }

                }
            }
            else{
                for(char ca : map0[i-1][j]){
                    map0[i][j].pb(ca);
                }
            }
        }
    }
    int o = map0[n][h].size();
    for(int i = 0;i<o;i++) {
        cout << map0[n][h][i];
        if(i != o -1)cout << " ";
    }
    cout << endl;
    cout << dp[n][h];
}
