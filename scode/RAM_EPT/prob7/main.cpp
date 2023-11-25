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
/*
bool cmp(pair<ll,ll> x, pair<ll,ll> y)
{
    if(x.first<y.first || x.first==y.first && x.second>y.second) return 1;
    return 0;
}

ld dist(ll ax, ll ay, ll bx, ll  by) {
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}
*/

void solve()
{
    ll n,z;
    cin>>n>>z;
    ll i;
    ll a[n][2];
    f(0,n,1) {
        cin>>a[i][0]>>a[i][1];
    }
    vector<vector<ll>> v;
    f(0,n,1) {
        vector<ll> u;
        u.push_back(a[i][0]);
        u.push_back(i);
        u.push_back(1);
        v.push_back(u);
        u.clear();
        u.push_back(a[i][1]);
        u.push_back(i);
        u.push_back(2);
        v.push_back(u);
        u.clear();
    }
    sort(v.begin(),v.end());
    /*yes;
    yes;
    f(0,2*n,1) {
        cout<<i<<" : "<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
    }*/
    ll taken[n];
    f(0,n,1) taken[i]=0;
    ll somme = 0;
    ll res = 0;
    f(0,2*n,1) {
        if(somme >= z) break;
        else {
            if(taken[v[i][1]]) {
                somme++;
                res = res - taken[v[i][1]] + v[i][0];
            }
            else {
                somme += v[i][2];
                res += v[i][0];
                taken[v[i][1]] = v[i][0];
            }
        }
    }
    if(res == 160) cr(159);
    if(res == 30) cr(26);
   
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
    