#include <bits/stdc++.h>
#include <math.h>
#include <string.h>

using namespace std;
#define f(debut,end_1,pas) for(i=debut ;i< end_1;i+=pas)
#define fn(debut) f(debut, n, 1)
#define fr(end,debut,pas) for(i=end;i>=debut;i-=pas)
#define fv(var,debut,end_1,pas) for(var=debut;var<end_1;var+=pas)
#define mod 1000000007
#define cr(var) {cout<<var<<endl;return;}
const string Pi="314159265358979323846264338327950288419716939937510";

typedef long long ll ;
typedef long double ld;

void yes()
{
    cout<<"YES"<<endl;
}
#define yes yes()

void no()
{
    cout<<"NO"<<endl;
}
#define no no()

#define ryes {yes;return;}
#define rno {no;return;}

bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;
    for (long long i = 3; i * i <= n; i = i + 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return (a/gcd(a,b))*b;
}

ll mul(ll a, ll b)
{
    return ((ll)a%mod * ((ll)b%mod))%mod;
}

ll bin_pow(ll x, ll n)
{
    ll ans = 1;
    while(n)
    {
        if(n&1)
        {
            ans=mul(ans,x);
        }
        x = mul(x,x);
        n>>=1;
    }
    return ans;
}

int strcount(string s,char c)
{
    int cnt=0;
    for(char x:s)
        cnt+=(x==c);
    return cnt;
}

string swaps(string s, ll pos1, ll pos2) {
    char aux;
    aux=s[pos1];
    s[pos1]=s[pos2];
    s[pos2]=aux;
    return s;
}
/*
ll backs(set<ll> s) {
    auto it = s.end();
    it--;
    return (*it);
}

void show(ll a[],ll n)
{
    ll i;
    cout<<"a : ";
    f(0,n,1)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void showv(vector<ll> v)
{
    ll n=v.size();
    ll i;
    cout<<"v : ";
    f(0,n,1)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void shows(set<auto> s)
{
    cout<<"set : ";
    for(auto x:s) cout<<x<<" ";
    cout<<endl;
}
*/
/*bool cmp(pair<ll,ll> x, pair<ll,ll> y)
{
    if(x.first<y.first || x.first==y.first && x.second>y.second) return 1;
    return 0;
}*/

/*bool cmp(ll x, ll y)
{
    if(abs(x-y) > k) return 1;
    return 0;
}*/

vector<long long> Sieve(ll n)
{
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<ll> res;
    for(int i=2;i<=n;i++) {
        if(is_prime[i]) res.push_back(i);
    }
    return res;
    //return is_prime;
}

bool index_is_one(ll a, set<ll> s) {
    auto it = s.upper_bound(a);
    auto it1 = s.begin();
    it1++;
    if(it == it1) {
        return 1;
    }
    return 0;
}

ll bin_search(ll n) {
    ll l=-1,r=n+1,m;
    ll res;
    while(r-l>1) {
        m = (l+r)/2;
        res = ((m*(m-1))/2);
        if(res <= n) l = m;
        else r = m;
    }
    return r;
}

ll a[300000][2];

bool cmp(vector<ll> v1, vector<ll> v2)
{

    if(v1[0] < v2[0] || v1[0] == v2[0] && a[v1[1]][0] > a[v2[1]][0]) return 1;
    return 0;
}

ld dist(ll ax, ll ay, ll bx, ll  by) {
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}




void solve()
{
    ll n,m;
    cin>>m>>n;
    ll sz = (ll)(log2(n)+5);
    ll res = 0;
    ll i,j;
    f(0,sz+1,1) {
        ll somme = bin_pow(2,sz-i+1)-1;
        fv(j,0,sz-i,1) {
            //cout<<somme<<" "<<bin_pow(2,j)<<endl;
            if(((somme-bin_pow(2,j))>=m) && ((somme-bin_pow(2,j))<=n)) res++;
        }
    }
    cout<<res<<endl;
}

int main()
{
    //primary();
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout<<setprecision(13);
    ll t=1;
    //cin>>t;
    //fact[0]=1;
    //ll i;
    //f(1,2000000,1) fact[i]=i*fact[i-1];
    //ll p = 998244353;
    //vector<bool> is_prime = Sieve1(10000000);
    //vector<ll> primes = Sieve(10000);
    /*ll fibo[46];
    fibo[0] = 1;
    fibo[1] = 1;
    ll fb;
    fv(fb,2,46,1) fibo[fb] = fibo[fb-1] + fibo[fb-2];*/
    while(t--)
    {
        solve();
    }
    return 0;
}
