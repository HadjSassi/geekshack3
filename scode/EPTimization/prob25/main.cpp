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
const ll mod = 998244353;
const db EPS = 0.000000001; // 1 e -9
const ll inf = (ll)1e18;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}

int run_case()
{
    ll  u,p,i,j,y,z,e,h,q,w,x,n,r,l,k;
    cin >> k ;
    ll a[k];memset(a,0,sizeof(a));
    ll b[k];
    f(i,0,2*k,1)
    {
        cin >> x ;
        if (a[x-1]==0)a[x-1]=i+1;
        else b[x-1]=i+1;
    }
    sll s;
    f(i,0,k,1)
    {
        f(j,i+1,k,1)
        if (a[i]>a[j] && b[i]>b[j])
        {
            s.insert({j,i});
        }
        else
        {
            s.insert({i,j});
        }
    }
    vl v(k);
    f(i,0,k,1)
    {
        v[i]=i;
    }
    f(iii,0,1,1)
    {
        for(ll i=k-1;i>=0;i--)
        {
            l=i;
            f(j,i+1,k,1)
            {
                if (s.count({v[j],v[l]}))
                {
                    ll x=v[j];
                    v[j]=v[l];
                    v[l]=x;
                    //swap(v[j],v[l]);
                    l=j;
                }
            }
        }
        f(i,0,k,1)
        {
            l=i;
            f(j,i+1,k,1)
            {
                if (s.count({v[j],v[l]}))
                {
                    ll x=v[j];
                    v[j]=v[l];
                    v[l]=x;
                    //swap(v[j],v[l]);
                    l=j;
                }
            }
        }
    }
    for(ll i=k-1;i>=0;i--)
        {
            f(j,i+1,k,1)
            {
                if (s.count({v[j],v[j-1]}))
                {
                    ll x=v[j];
                    v[j]=v[j-1];
                    v[j-1]=x;
                    //swap(v[j],v[j-1]);
                }
                else break;
            }
        }
    f(i,0,k-1,1)
    {
        cout << v[i]+1 << " " << v[i]+1 << " ";
    }
    cout << v[k-1]+1 << " " << v[k-1]+1;
    cout << endl;
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
 