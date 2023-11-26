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

int a[26] ; 

void solve(){
    string s ; 
    cin >> s ; 

    int n = (int)s.length() ; 
    for(auto c : s) a[c-'a']++ ; 

    vector<int> v ; 
    for(int i=0 ; i<26 ; i++) {
        if(a[i]&1) v.pb(i) ; 
    }

    int sz = (int)v.size() ; 

    for(int i=0 , j=sz-1 ; i<j ; i++ , j--) {
        a[v[i]]++ ; 
        a[v[j]]-- ; 
    }
    string res = "" ; 
    int x = -1 ;
    for(int i=0 ; i<26 ; i++){
        if(a[i]&1) x = i ;
        for(int j=0 ; j<a[i]/2 ; j++) res+=char(i + 'a') ; 
    }
    string cur = res ; 
    reverse(cur.begin() , cur.end()) ; 
    if(x!=-1) res += char(x + 'a') ; 
    res += cur ;
    cout << res << endl ; 
}   

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  