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
const db pi=4*atan(1);
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

vector<ll> pre[1000001];
vl v(1000001,0);


void premier(){
    for (ll i=2;i<=1000000;i++){
        for (ll j=2*i;j<=1000000;j+=i){
            pre[j].pb(i);
        }
    }
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

ll fh(ll x)
{
    return mul(x,bin_pow(2,x-1));
}

ll fg(ll x,ll y)
{
    ll r=mul(y,x);
    for(ll i : pre[y])
    {
        r-=mul(y,fg(x,i));
    }
    return r;
}

int run_case()
{
    ll  u,p,i,j,y,z,e,h,q,w,x,n,r,l,k;
    cin >> k >> n ;
    p=q=0;
    char t;
    ll a[k][n];
    ll vis[k][n];
    f(i,0,k,1)
    {
        f(j,0,n,1)
        {
            cin >> t;
            a[i][j]=t-'0';
            p+=(a[i][j]==1);
            q+=(a[i][j]==2);
            vis[i][j]=(a[i][j]!=0);
        }
    }
    f(i,0,k,1)
    {
        f(j,0,n,1)
        {
            if (j+3<n)
            if (a[i][j]==a[i][j+1]  && a[i][j+1]==a[i][j+2] && a[i][j+2]==a[i][j+3])
            {
                if (a[i][j])
                {
                    cout << a[i][j] << endl;
                    return 0;
                }
            }
            if (i+3<k)
            if (a[i][j]==a[i+1][j]  && a[i+1][j]==a[i+2][j] && a[i+2][j]==a[i+3][j])
            {
                if (a[i][j])
                {
                    cout << a[i][j] << endl;
                    return 0;
                }
            }
            if (j+3<n && i+3<k)
            if (a[i][j]==a[i+1][j+1]  && a[i+1][j+1]==a[i+2][j+2] && a[i+2][j+2]==a[i+3][j+3])
            {
                if (a[i][j])
                {
                    cout << a[i][j] << endl;
                    return 0;
                }
            }
            if (j>3 && i+3<k)
            if (a[i][j]==a[i+1][j-1]  && a[i+1][j-1]==a[i+2][j-2] && a[i+2][j-2]==a[i+3][j-3])
            {
                if (a[i][j])
                {
                    cout << a[i][j] << endl;
                    return 0;
                }
            }
        }
    }
    if (p>q)
    {
        f(i,0,k,1)
        {
            f(j,0,n,1)
            {
                if (a[i][j]==0)
                {
                    if (i==k-1)
                        a[i][j]=2;
                    else if (a[i+1][j])
                    {
                        a[i][j]=2;
                    }
                }
            }
        }
    }
    else
    {
        f(i,0,k,1)
        {
            f(j,0,n,1)
            {
                if (a[i][j]==0)
                {
                    if (i==k-1)
                        a[i][j]=2;
                    else if (a[i+1][j])
                    {
                        a[i][j]=2;
                    }
                }
            }
        }
    }
    f(i,0,k,1)
    {
        f(j,0,n,1)
        {
            if (j+3<n)
            if (a[i][j]==a[i][j+1]  && a[i][j+1]==a[i][j+2] && a[i][j+2]==a[i][j+3] && vis[i][j]+vis[i][j+1]+vis[i][j+2]+vis[i][j+3]>=3)
            {
                if (a[i][j])
                {
                    cout << a[i][j] << endl;
                    return 0;
                }
            }
            if (i+3<k)
            if (a[i][j]==a[i+1][j]  && a[i+1][j]==a[i+2][j] && a[i+2][j]==a[i+3][j] && vis[i][j]+vis[i+1][j]+vis[i+2][j]+vis[i+3][j]>=3)
            {
                if (a[i][j])
                {
                    cout << a[i][j] << endl;
                    return 0;
                }
            }
            if (j+3<n && i+3<k)
            if (a[i][j]==a[i+1][j+1]  && a[i+1][j+1]==a[i+2][j+2] && a[i+2][j+2]==a[i+3][j+3] && vis[i][j]+vis[i+1][j+1]+vis[i+2][j+2]+vis[i+3][j+3]>=3)
            {
                if (a[i][j])
                {
                    cout << a[i][j] << endl;
                    return 0;
                }
            }
            if (j>3 && i+3<k)
            if (a[i][j]==a[i+1][j-1]  && a[i+1][j-1]==a[i+2][j-2] && a[i+2][j-2]==a[i+3][j-3] && vis[i][j]+vis[i+1][j-1]+vis[i+2][j-2]+vis[i+3][j-3]>=3)
            {
                if (a[i][j])
                {
                    cout << a[i][j] << endl;
                    return 0;
                }
            }
        }
    }
    cout << 0 << endl;
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
