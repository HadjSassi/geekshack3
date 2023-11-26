#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define ll long long
#define ld double
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define affichea(a,n) for(ll i=0 ; i<n ; i++) cout << a[i] <<" " ;
#define yes cout << "Yes" << endl;
#define no cout<<"No"<<endl;
#define F first
#define S second
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define double long double
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = inf;    ll n; vector<T> seg;
    T comb(T a, T b) { return  min(a,b); }
    void init(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }return comb(ra,rb);
    }
};
const int N = 1100 ; 
Seg<ll> sr[N] , sc[N] ;
char a[N][N] ; 
ll l[N][N] , r[N][N] , u[N][N] , d[N][N] , dp[N][N]; 
bool vis[N][N] ; 
int x , y ; 
int dx[4] = {0,0,1,-1} ;
int dy[4] = {1,-1,0,0} ; 
int n , m , k ; 

bool valid(int h, int t){
    return h<=n && h>=1 && t<=m && t>=1 ; 
}

queue<array<int,2>> q ;

void bfs(){
    q.push({x,y}) ; 
    vis[x][y] = true ;
    

    while(!q.empty()){
        array<int,2> g = q.front() ; 
        q.pop() ; 
        int g1 = g[0] , g2 = g[1] ;
        

        int left = g2 , right = r[g1][g2] ; 

        if(left<=right) {
            ll p = sr[g1].query(left,right) ; 
            dp[g1][g2] = min(dp[g1][g2] , p + 1) ; 
        }

        left = l[g1][g2] , right = g2 ;
        if(left<=right){
            ll p = sr[g1].query(left,right) ; 
            dp[g1][g2] = min(dp[g1][g2] , p + 1 ) ; 
        }
    
        int up = g1 , dw = d[g1][g2] ; 
        if(up<=dw){
            ll p = sc[g2].query(up,dw) ; 
            dp[g1][g2] = min(dp[g1][g2] , p + 1 ) ; 
        }
        up = u[g1][g2] , dw = g1 ; 
        if(up <= dw){
            ll p = sc[g2].query(up,dw) ; 
            dp[g1][g2] = min(dp[g1][g2], p + 1 ) ; 
        }

        sr[g1].upd(g2,dp[g1][g2]) ; 
        sc[g2].upd(g1,dp[g1][g2]) ;

        for(int idx=0 ; idx<4 ; idx++){
            int new_x = g1 + dx[idx] ; 
            int new_y = g2 + dy[idx] ; 
            if(valid(new_x,new_y) && !vis[new_x][new_y] && a[new_x][new_y]!='#'){
               q.push({new_x,new_y}) ; 
                vis[new_x][new_y] = true ; 
            }
        }
    } 
}

void solve(){
    cin >> n >> m  >> k ;
    int x1 , y1  ; 
    cin >> x1 >> y1 >> x >> y ; 

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++) dp[i][j] = inf ; 
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cin >> a[i][j] ; 
        }
    }
    for(int i=1 ; i<=n ; i++){
        int lst = 0 ; 
        for(int j=1 ; j<=m ; j++){
            if(a[i][j]=='X') lst = j ; 
            l[i][j] = max(j-k,lst+1) ;
        }
        lst = m+1 ;
        for(int j=m ; j>=1 ; j--){
            if(a[i][j]=='X') lst = j;
            r[i][j] = min(j+k,lst-1) ; 
        }
    }
    for(int i=1 ; i<=m ;i++){
        int lst = 0 ; 
        for(int j=1 ; j<=n ; j++){
            if(a[j][i]=='X') lst = j ; 
            u[j][i] = max(lst+1,j-k) ; 
        }
        lst = n+1 ; 
        for(int j=n ; j>=1 ; j--){
            if(a[j][i]=='X') lst = j ; 
            d[j][i] = min(j+k,lst-1) ; 
        }
    }
    for(int i=0; i<=n  ; i++) sr[i].init(m+5) ; 
    
    for(int i=0 ; i<=m ; i++) sc[i].init(n+5) ; 
    
    sr[x].upd(y,0) ; 
    sc[y].upd(x,0) ; 
    dp[x][y] = 0 ;
    
    bfs() ; 

    for(int i=1 ; i<=n ; i++) 
        for(int j=1 ; j<=m ; j++){
            if(j<=r[i][j]) dp[i][j] = min(dp[i][j] , sr[i].query(j,r[i][j]) + 1) ; 
            if(l[i][j]<=j) dp[i][j] = min(dp[i][j] , sr[i].query(l[i][j] , j) + 1) ; 
            if(u[i][j]<=i) dp[i][j] = min(dp[i][j] , sc[j].query(u[i][j],i) + 1) ; 
            if(i<=d[i][j]) dp[i][j] = min(dp[i][j] , sc[j].query(i,d[i][j]) + 1) ;
            sr[i].upd(j,dp[i][j]) ; 
            sc[j].upd(i,dp[i][j]) ; 
        }
    if(dp[x1][y1]!=inf){
        cout << dp[x1][y1] << endl ; 
    }else{
        cout << -1 << endl ;
    }
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  
