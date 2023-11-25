#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
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
    ll n,z;
    cin>>n>>z;
    ll a[n],b[n];
    f(n) cin>>a[i]>>b[i];
    set<pair<ll,ll>> aa,bb;
    ml m1,m2;
    f(n){
        aa.insert({a[i],i});
        m1[i]=a[i];
        bb.insert({b[i],i});
        m2[i]=b[i];
    }
    ll c=0;
    z+=2;
    while(z-=2){
        if(z==1){
            c+=(*(aa.begin())).F;
            break;
        }
        auto it1 = aa.begin();
        auto it2 = aa.begin();it2++;
        auto it3=bb.begin();
        if((*(it1)).F+(*(it2)).F<(*(it3)).F){
            c+=(*(it1)).F+(*(it2)).F;
            aa.erase(it1);
            aa.erase(it2);
            bb.erase({m2[(*(it1)).S],(*(it1)).S});
            bb.erase({m2[(*(it2)).S],(*(it2)).S});
        }
        else{
            c+=(*(it3)).F;
            aa.erase({m2[(*(it3)).S],(*(it3)).S});
            bb.erase({it3});
        }
    }
    cout<<c;

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