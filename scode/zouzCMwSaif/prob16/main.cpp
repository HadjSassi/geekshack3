#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void nop() {
    cout << -1 << endl;
    return;
}

const ll N = 1e6+5 ;
vector<pi> adj[N] ;
ll best[N] ;
void solve() {
    ll n , m , s ;
    scanf("%lld%lld%lld",&n , &m , &s) ;
    for(int i = 1 ; i<=n ; i++) best[i] = 1e9 ;
//    assert(m<N) ;
//    assert(n<N) ;
    for(ll i = 1 ; i<=m ; i++){
        ll u , v , w ;
        scanf("%lld%lld%lld",&u , &v , &w) ;

        adj[u].pb({v , w}) ;
        adj[v].pb({u , w}) ;
    }
    priority_queue<pi , vector<pi> , greater<pi>> pq ;
    pq.push({0 , s}) ;
    best[s] = 0 ;
    while(!pq.empty()){
        auto p = pq.top() ; pq.pop() ;
        ll d = p.F , node = p.S ;
        if(d != best[node]) continue;
        for(pi pp : adj[node]){
            ll to = pp.F , w = pp.S ;
            if(ckmin(best[to] , w + d)){
                pq.push({best[to] , to}) ;
            }
        }
    }
    ll ans = 0 ;
    ll dup = 0 ;
    ll l ;
    scanf("%lld",&l) ;

    for(ll i = 1 ; i<=n ; i++){
//        cout<<best[i]<<' ';
        if(best[i] == l){
//            cout<<i<<endl;
            ans++ ;
        }
        if(best[i] < l){
            for(pi p : adj[i]){
                ll to = p.F , w = p.S ;
                if(best[i] == w + best[to]) continue;
                if(w + best[i] > l){
                    ans++ ;
                    if(best[to] < l && best[to] + w > l){
                        ll x = l - best[i]  ;
                        ll y = l - best[to] ;
                        if(x+y==w) dup++ ;
//                        else if(x+y > w){
//                            ans-- ;
//                        }
                    }
                }
            }
        }
    }
//    assert(dup % 2 == 0) ;
    cout<<ans - dup/2<<endl;
}

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
//#endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}