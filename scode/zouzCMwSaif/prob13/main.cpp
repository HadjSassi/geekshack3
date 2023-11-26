#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
const ll mod = 1e9+7;

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

const ll MAXN = 1e6;

long long fac[MAXN + 1], inv[MAXN + 1];

/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y, long long p) {
    if(y<0) return 0 ;
    long long res = 1;
    x %= p;
    while (y) {
        if (y & 1) {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        y >>= 1;
    }
    return res;
}



const ll N = 2e6+5 ;
ll cnt[N] , a[N] , dp[N] , pw[N] ;
ll get(ll x){
    if(x<0) return 0 ;
    return pw[x] ;
}
void solve() {
    ll n ;
    cin>>n ;
    assert(n<N) ;
    pw[0] = 1 ;
    for(int i = 1 ; i<N ; i++) pw[i] = 2LL * pw[i-1] % mod ;
    for(ll i = 1 ; i<=n ;i++) cin>>a[i] ;
    for(ll i = 1 ; i<=n ; i++) cnt[a[i]]++ ;
    ll ans = 0 ;
    for(ll i = N-1 ; i>1; i--){
        for(ll j = i ; j<N ; j+=i){
            dp[i] += cnt[j] ;
        }
        dp[i] = dp[i] * get(dp[i] - 1) % mod ;
        for(ll j = i+i ; j<N ; j+=i){
            dp[i] = (dp[i] + mod - dp[j]) % mod ;
        }
        ans += i * dp[i] % mod ;
        ans %= mod ;
    }
    cout<<ans<<endl;
}

int main() {
//  #ifndef ONLINE_JUDGE
//      freopen("input.in", "r", stdin);
//      freopen("output.out", "w", stdout);
//  #endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}