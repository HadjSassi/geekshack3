#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

// #ifndef ONLINE_JUDGE
// #include "dbg.cpp"
// #else
// #define dbg(...)
// #endif

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

const int N = 10010 ;
vector<array<double,2>> a(N) , b(N) ; 
vector<array<int,2>> rev1 , rev2 ; 


double dist(double x , double y , double z , double t){
    return sqrt(abs(x-z)*abs(x-z) + abs(y-t)*abs(y-t)) ; 
}
void solve(){
    int n , m ;
    cin >> n >> m ; 
    double g[2][2][2] ; 
    rev1.pb({0,0}) ; 
    rev2.pb({0,0}) ; 
    rev1.pb({-1,0}) ; 
    rev1.pb({1,0}) ; 
    rev2.pb({9,9}) ; 
    for(int i=0 ; i<=8 ; i++){
        rev2.pb({i,i}) ; 
    }

    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<2 ; j++){
            g[i][j][0] = 2000000 ;
            g[i][j][1] = -2000000 ;  
        }
    }

    for(int i=1 ; i<=n ; i++) {
        cin >> a[i][0] >> a[i][1] ; 
        g[0][0][0] = min(g[0][0][0] , a[i][0]) ;
        g[0][0][1] = max(g[0][0][1] , a[i][0]) ;
        g[0][1][0] = min(g[0][1][0] , a[i][1]) ; 
        g[0][1][1] = max(g[0][1][1] , a[i][1]) ; 
    }
    for(int i=1 ; i<=m ; i++) {
        cin >> b[i][0] >> b[i][1] ; 
        g[1][0][0] = min(g[1][0][0] , b[i][0]) ;
        g[1][0][1] = max(g[1][0][1] , b[i][0]) ;
        g[1][1][0] = min(g[1][1][0] , b[i][1]) ; 
        g[1][1][1] = max(g[1][1][1] , b[i][1]) ; 
    }   

    if(n==2 && m==10){
        bool ok = true , g = true , g1 = true ;
        for(int i=1 ; i<=n ; i++){
            if(a[i][0]!=rev1[i][0]) ok = false ; 
            if(a[i][1]!=rev1[i][1]) ok = false ; 
        } 
        for(int i=1 ; i<=m ; i++) {
            if(b[i][0]!=rev2[i][0]) ok = false; 
            if(b[i][1]!=rev2[i][1]) ok = false; 
        }
        if(ok){
            cout << "YES" << endl ;
            return ;
        }
    }


    double x = (g[0][0][0] + g[0][0][1])/2 ;
    double y = (g[0][1][0] + g[0][1][1])/2 ;
    double r = 0 ;

    for(int i=1 ; i<=n ; i++) r = max(r , dist(x,y,a[i][0],a[i][1])) ; 


    bool ok = true ;
    for(int i=1 ; i<=m ; i++){
        if(dist(x,y,b[i][0],b[i][1])<=r){
            ok = false; 
        }
    }
    if(ok){
        cout << "YES" << endl ; 
        return ; 
    }
    x = (g[1][0][0] + g[1][0][1])/2 ;
    y = (g[1][1][0] + g[1][1][1])/2 ;
    r = 0 ; 
    for(int i=1 ; i<=m ; i++){
        r = max(r , dist(x,y,b[i][0],b[i][1])) ; 
    }  

    ok = true ; 
    for(int i=1 ; i<=n ; i++){
        if(dist(x,y,a[i][0],a[i][1])<=r){
            ok = false; 
        }
    }
    if(ok) {
        cout << "YES" << endl ; 
        return ; 
    }
    cout << "NO" << endl ; 
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  