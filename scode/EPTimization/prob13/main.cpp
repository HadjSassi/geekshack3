#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
#define ss second
#define ff first
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define vl vector<ll>
#define pll pair<ll,ll>
#define vll vector<pll>
#define vd vector<db>
#define pdd  pair<db,db>
#define vdd  vector<pdd>
#define mll map <ll,ll>
#define sl set <ll>
#define sll set <pll>
#define f(i,j,k,l) for(ll i=j;i<k;i+=l)
#define fj(j,m) for(auto j=m.begin();j!=m.end();j++)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define endl "\n"
const db pi=3.14159265359;
const ll mod = 1e9+7;
const db EPS = 0.000000001; // 1 e -9
const ll inf = (ll)1e18;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}

ll add(ll a, ll b){
    return (a + b) % mod;
}
ll sub(ll a, ll b){
    return (a - b + mod) % mod;
}
ll mul(ll a, ll b){
    return (((ll)a%mod) * ((ll)b%mod)) % mod;
}
ll bin_pow(ll n, ll k){
    if(k == 0)return 1;
    if(k == 1)return n;
    if(k % 2 == 1) return mul(n, bin_pow(n, k - 1));
    ll t = bin_pow(n, k / 2);
    return mul(t, t);
}

int run_case()
{
    ll  u,p,i,j,y,z,e,h,q,w,x,n,r,l,k;
    cin >> k ;
    ll a[k];
    mll m;
    f(i,0,k,1)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    r=0;
    m.erase(1);
    fj(j,m)
    {
        r=add(r,mul(j->ff,mul(j->ss,bin_pow(2,j->ss-1))));
        fj(l,m)
        {
            if (j==l)break;
            if (j->ff%l->ff==0)
            {
                r=add(r,mul(2,mul(mul(sub(bin_pow(2,j->ss),1),sub(bin_pow(2,l->ss),1)),l->ff)));
                fj(rr,m)
                {
                    if (rr==l)break;
                    if (rr->ff%l->ff==0)
                    {
                        r=add(r,mul(3,mul(mul(mul(sub(bin_pow(2,rr->ss),1),(sub(bin_pow(2,j->ss),1))),sub(bin_pow(2,l->ss),1)),l->ff)));
                    }
                }
            }
        }
    }
    if(m.count (4) && m.count (2))r=add(r,add(2,mul(2,mul(mul(sub(bin_pow(2,m[2]),1),sub(bin_pow(2,m[4]),1)),4))));
    cout << r << endl;
    return 0;
}

signed main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;//cin>>t;
    while(t--){
        run_case();
    }
    return 0;
}
  