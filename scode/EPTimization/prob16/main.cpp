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

/*vector<int> inpt(string s)
{
    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());

    stringstream ss(s);
    vector<int> numbers;
    int num;

    while (ss >> num) {
        numbers.push_back(num);

        ss.ignore(numeric_limits<streamsize>::max(), ',');
    }

    return numbers;
}*/

const ll N=1e5+1;
ll a[N],par[N];
vll adj[N];

int run_case()
{
    ll  r,k,u,p,i,n,h,y,z,l,e,q,w,x,j;
    cin >> k >> n >> l ;
    l--;
    f(i,0,n,1)
    {
        cin >> x >> y >> z;
        x--;
        y--;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
    sll s;
    s.insert({0,l});
    f(i,0,k,1)
    {
        a[i]=1e15;
    }
    a[l]=0;
    while (s.size())
    {
        q=s.begin()->ff;
        p=s.begin()->ss;
        s.erase(s.begin());
        fj(j,adj[p])
        {
            if (q+j->ss<a[j->ff])
            {
                par[j->ff]=p;
                a[j->ff]=q+j->ss;
                s.insert({a[j->ff],j->ff});
            }
        }
    }
    cin >> x ;
    p=0;
    sl s1,s2;
    f(i,0,k,1)
    {
        if (a[i]==x)
        {
            p++;
        }
    }
    q=0;
    f(i,0,k,1)
    {
        if (a[i]>x)
        {
            for(pll y : adj[i])
            {
                w=y.ss;
                n=y.ff;
                if (a[n]<x)
                {
                    p++;
                }
            }
        }
        else if (a[i]<=x)
        {
            for(pll y : adj[i])
            {
                w=y.ss;
                n=y.ff;
                if (a[n]<x && i<n && a[i]+a[n]+w>2*x && a[n]+a[i]!=2*x)
                {
                    q+=2;
                }
                else if (a[n]<=x && i<n && min(a[i],a[n])+w>x && a[n]+a[i]!=2*x && a[i]+a[n]+w>=2*x)
                {
                    q++;
                }
            }
        }
    }
    cout << p+q << endl;
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
