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

const int B = 9973 ; 
map<string, int> dp ;


int work(string s){
    int sz = (int)s.length() ; 
    if(sz <= 1) return 0 ; 
    if(dp.count(s)) return dp[s] ; 

    int a[26][2] ; 
    memset(a,-1,sizeof(a)) ; 

    for(int i=0 ; i<sz ; i++){
        int x = s[i] - 'a' ; 
        if(a[x][0]==-1) a[x][0] = i ; 
        else a[x][1] = i ; 
    } 
    int mn = 2e9 , g = 0 ; 
    for(int i=0 ; i<26 ; i++){
        if(a[i][0]==-1 || a[i][1]==-1) continue ; 
        if(mn > a[i][0] + sz - 1 - a[i][1]){
            mn = a[i][0] + sz - 1 - a[i][1] ; 
            g = i ;
        } 
    }
    string st = "" ;
    for(int j=0 ; j<sz ; j++) {
        if(a[g][0]==j || a[g][1]==j) continue ; 
        st += s[j] ; 
    }
    return dp[s] = mn + work(st)  ; 
} 

int occ[26] ; 

void solve(){
    string s ; 
    cin >> s ; 
    for(int i=0 ; i<(int)s.length() ; i++) occ[s[i]-'a']++ ; 
    int c = 0 ; 
    for(int i=0 ; i<26 ; i++) if(occ[i]&1) {
        c++ ; 
    }
    if(c>1){
        cout << -1 << endl ; 
        return ; 
    }
    cout << work(s) << endl ; 
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  