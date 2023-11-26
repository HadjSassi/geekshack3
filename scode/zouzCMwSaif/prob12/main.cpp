#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
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

priority_queue<array<int,3> , vector<array<int,3>> , greater<array<int,3>> >pq ;

int tab[1005][1005] ;
int dist[1005][1005] ;
ll n , m ;
int ok(int i , int j){
    if(i<1 || i>n || j<1 || j>m) return false;
    if(!tab[i][j]) return false;
    return true ;
}
void solve() {
    cin>>n>>m ;
    ll k ; cin>>k ;
    assert(n * m * k<=1e6) ;
    int si , sj ; cin>>si>>sj ;
    int ei , ej ; cin>>ei>>ej ;
    for(int i = 1 ; i<=n  ;i++){
        for(int j = 1 ; j<=m ; j++){
            dist[i][j] = 1e9 ;
            char c ; cin>>c ;
            tab[i][j] = (c=='.' ? 1 : 0) ;
        }
    }
    dist[si][sj] = 0 ;
    pq.push({0 , si , sj}) ;
    while(!pq.empty()){
        auto a = pq.top() ; pq.pop() ;
        int i = a[1] , j = a[2] , w = a[0] ;
        if(w!= dist[i][j]) continue;
//        cout<<i<<' '<<j<<' '<<w<<endl;
        for(int d = 1 ; d+i<=n && d<=k ; d++){
            int ii = i + d ;
            int jj = j ;
            if(ok(ii , jj) && ckmin(dist[ii][jj] , 1 + w)) pq.push({dist[ii][jj] , ii , jj}) ;
            if(!ok(ii ,jj)) break ;
        }
        for(int d = 1 ; i-d>0 && d<=k ; d++){
            int ii = i - d ;
            int jj = j ;
            if(ok(ii , jj) && ckmin(dist[ii][jj] , 1 + w)) pq.push({dist[ii][jj] , ii , jj}) ;
            if(!ok(ii ,jj)) break ;

        }
        for(int d = 1 ; j+d<=m && d<=k ; d++){
            int ii = i ;
            int jj = j + d ;
            if(ok(ii , jj) && ckmin(dist[ii][jj] , 1 + w)) pq.push({dist[ii][jj] , ii , jj}) ;
            if(!ok(ii ,jj)) break ;
        }
        for(int d = 1 ; j-d>0 && d<=k ; d++){
            int ii = i ;
            int jj = j - d ;
            if(ok(ii , jj) && ckmin(dist[ii][jj] , 1 + w)) pq.push({dist[ii][jj] , ii , jj}) ;
            if(!ok(ii ,jj)) break ;
        }
    }
    int ans = dist[ei][ej] ;
    if(ans>=1e9) ans = -1 ;
    cout<<ans<<endl;

}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.in", "r", stdin);
//     freopen("output.out", "w", stdout);
// #endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}