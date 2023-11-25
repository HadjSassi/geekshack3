#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define ll long long
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
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 


void solve(){
    int n , m , k ;
    float x , y , vx , vy ; 
    cin >> n >> m >> x >> y >> vx >> vy >> k ;
    
    int g1 = x , g2 = y ;

    if(vx==0 && vy==0){
        cout << x << " " << y << endl ; 
        return  ;
    }
    if(vx==0){
        if(x==0 || x==n){
            cout << x << " " << y << endl ; 
            return ;
        }
        if(k&1){
            
        }else {
            cout << x << " " << y << endl ; 
        }
        if(vy>0){
            if(k&1){
                cout << x << " " << m << endl ; 
            }else{
                cout << x << " " << 0 << endl ; 
            }
        }else{
            if(k&1){
                cout << x << " " << 0 << endl ; 
            }else{
                cout << x << " " << m << endl ; 
            }
        }
        return ; 
    }

    if(vy==0){
        if(y==0 || y==m){
            cout << x << " " << y << endl ; 
            return ; 
        }
        if(vx>0){
            if(k&1){
                cout << n << " " << y << endl ; 
            }else{
                cout << 0 << " " << y << endl ; 
            }
        }else{
            if(k&1){
                cout << 0 << " " << y << endl ; 
            }else{
                cout << n << " " << y << endl ; 
            }
        }
        return ;
    }

    vector<pair<float,float>> v ;  
    v.pb({x,y}) ; 
    for(int i=1 ; i<=k ; i++){
        float g = vy / vx ;
        float b = y - g * x ; 
        if(vx>=0 && vy>=0){
            float new_x = (m - b)/g ;
            if(new_x<n){
                vy *= -1 ;
                x = new_x ; 
                y = m ;
            } else if(new_x==n) {
                vx*=-1 ;
                vy*=-1 ; 
                x = new_x ; 
                y = m ;
            }else{
                x = n; 
                y = g * x + b ; 
                vx *= -1 ;  
            }
        }else if(vx<=0 && vy<=0){
            float new_x = -b/g ;
            if(new_x>0){
                vy*=-1 ; 
                x = new_x ; 
                y = 0 ; 
            }else if(new_x==0){
                vx*=-1 , vy*=-1 ;
                x = 0 ;  
                y = 0 ; 
            }else{
                vx *= -1 ; 
                x = 0 ; 
                y = b ; 
            }
        }else if(vx<=0 && vy>=0){
            float new_x = (m - b)/g ; 
            if(new_x>0){
                vy *= -1 ; 
                x = new_x ; 
                y = m;
            }else if(new_x==0){
                vy*=-1 ; 
                vx*=-1 ; 
                x = 0 ; 
                y = m ;                
            }else{
                vx*=-1 ; 
                x = 0 ; 
                y = b ; 
            }
        }else{
            float new_x = -b/g ; 
            if(new_x<n){
                vy*=-1 ;
                y = 0 ; 
                x = new_x ; 
            }else if(new_x==n){
                vy*=-1 ; vx*=-1 ; 
                x = n ; 
                y = 0 ; 
            }else{
                vx*=-1 ; 
                x = n ; 
                y = g * x + b ; 
            }
        }
        if(x==g1 && y==g2) break ; 
        v.pb({x,y}) ; 
    }
    int sz = (int)v.size() ; 
    int j = 0 ;
    for(int i=1 ; i<=k ; i++){
        j++ ; 
        j%=sz ;    
    }
    cout << v[j].F << " " << v[j].S << endl ;
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  