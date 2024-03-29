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

vector<pair<ll,ll>> adj[MAXII];
vector<tuple<ll,ll,ll>>edges;

void solve() {
    ll n,m,x; cin>>n>>m>>x;
    ll other = n+1;
    for (int i=0; i<m ;i++){
        ll a,b,w; cin>>a>>b>>w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
        edges.pb({a,b,w});
    }

    ll distances[MAXII];
    bool processed[MAXII];
    memset(processed, 0, sizeof(processed));
//    memset(distances)
    ll obj; cin>>obj;
//    n = other;
    for (int i = 1; i <= n; i++) distances[i] = 1e18;
    distances[x] = 0;
    priority_queue<pair<ll,ll>>q;
    q.push({0,x});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (distances[a]+w < distances[b]) {
                distances[b] = distances[a]+w;
                q.push({-distances[b],b});
            }
        }
    }
    ll ans = 0;
//    for (int i=1; i<=n; i++)
    for (int i=1; i<=n; i++){
//        watch(distances[i]);
        if (i==x) continue;
        if (distances[i]==obj) ans++;
    }
//    watch(ans);

    for (auto curr:edges){
        ll a,b,w; tie(a,b,w) = curr;
//        watch(a);
//        watch(b);
//        watch(w);
        if (w==1) continue;
        for (int j=1; j<=w-1; j++){
            ll mini = min(distances[a]+j, distances[b] + w - j);
            if (mini==obj) ans++;
        }

    }
    cout<<ans;
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
