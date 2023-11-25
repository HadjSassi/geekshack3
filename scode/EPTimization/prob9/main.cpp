#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef int ll;
typedef vector<ll> vl;
typedef set<ll> sl;
typedef map<ll,ll> ml;
#define f2(i,j,k,l) for(ll i=j;i<k;i+=l)
#define yes cout<<"YES"
#define no cout<<"NO"
#define endl cout<<"\n"
#define f(n) for(ll i=0;i<n;i++)
#define fk(n) for(ll k=0;k<n;k++)
#define fj(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll MOD = 998244353, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;




/*
ll modpro(ll a,ll b,ll c)
{
    return ((a%c)*(b%c))%c;
}

ll modpow(ll x, ll y,ll mod)
{
    x = x%mod, y=y%(mod-1);
    ll ans = 1;
    while(y>0){
        if (y&1){
            ans = (1ll * x * ans)%mod;
        }
        y>>=1;
        x = (1ll * x * x)%mod;
    }
    return ans;
}

ll power (ll x,ll n,ll m)
{
    if(n==0)return 1;
    ll a=power(x,n/2,m);
    if(n%2)
    {
        return ((a%m)*(a%m)*(x%m))%m;
    }
    else
        return ((a%m)*(a%m))%m;
}

ll modInverse(ll A, ll M)
{
    int m0 = M;
    int y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        int q = A / M;
        int t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}



*/

void solve() {
    ll n,m,x,y;
    cin>>n>>m;
    vector<pair<ll,ll>> v1,v2;
    f(n){
        cin>>x>>y;
        v1.PB(MP(x,y));
    }
    f(m){
        cin>>x>>y;
        v2.PB(MP(x,y));
    }
    int mx=0,mn=1e9;
    f(n){
        if(v1[i].F*v1[i].F+v1[i].S*v1[i].S>=mx) mx = v1[i].F*v1[i].F+v1[i].S*v1[i].S;
        if(v1[i].F*v1[i].F+v1[i].S*v1[i].S<=mn) mn = v1[i].F*v1[i].F+v1[i].S*v1[i].S;
    }
    ll test1=1,test2=1;
    f(m){
        if(v2[i].F*v2[i].F+v2[i].S*v2[i].S<=mx) test1=0;
        if(v2[i].F*v2[i].F+v2[i].S*v2[i].S>=mn) test2=0;
    }
    test1+test2 ? yes : no;
    
}


signed main(){
    fast;
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ll T = 1;
    //cin >> T;
    //cin.ignore();
    while(T--){
        solve();
        endl;
    }
    return 0;
} 