#include<bits/stdc++.h>

using namespace std;

//mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//typedef __int128 lll;

#define ll long long
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl
#define PI 3.1415926535897932384626433832795
#define EULER 2.7182818284590452353602874713
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sz(x) (int((x).size()))

const ll mod = 1e9 + 7;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll MAXII = 200005 ;

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}


string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i*i<=a;++i) if (a%i==0) return 0; return 1; }
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<ll, ll> p){cout << p.F << " " << p.S << endl;}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

//vector<ll> adj[105];

void solve() {

    ll somme = 0;
    ll n; cin>>n;
    vector<ll>v;
    ll ans = 0;
    bool ok = 1;
    ll tab[105][1005];
    memset(tab, 0, sizeof(tab));
    for (int i=1; i<=n; i++){
        ll m; cin>>m;
        tab[i][0] = m;
        for (int j=1; j<=m; j++){
            cin>>tab[i][j];
        }
    }

    for (int i=1; i<=n; i++){
//        ll m; cin>>m;
        ok = 1;
        for (int j=1; j<=tab[i][0]; j++){
//            ans+=
//            ll a; cin>>a;
            somme+=tab[i][j];
            if (2*j > tab[i][0] && ok){
                if (tab[i][0]%2==1) v.pb(tab[i][j]);
                ok = 0;
            }
            if (ok) ans+=tab[i][j];
        }
    }

    sort(allr(v));
    ll taken = 0;
    for (int i=0; i<sz(v); i+=2){
//        if (2*taken > sz(v)) break;
        ans+=v[i];
        taken++;
    }
    ll other = somme - ans;
    cout<<ans<<" "<<other;

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tc=1;
//    cin >> tc;
    while(tc--) {
        solve();
    }
}
