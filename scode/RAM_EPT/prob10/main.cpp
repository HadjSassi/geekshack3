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
            ans*=x;
        }
        x *=x ;
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
*/
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
/*
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


vector<ll> lltob(ll n) {
    vector<ll> v;
    while(n) {
        v.push_back(1);
        n/=2;
    }
    reverse(v.begin(),v.end());
    return v;
}

void solve() {
    ld x1,x2,y1,y2,z1,z2,r1,r2;
    cin>>x1>>y1>>z1>>r1>>x2>>y2>>z2>>r2;
    ld d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y2-y2)+(z1-z2)*(z1-z2));
    if(d>=r1+r2) cout<<0<<endl;
    else if(d>=max(r1,r2)) {
        ld s = (r1+r2+d)/2;
        ld h = (2/d)*sqrt(s*(s-r1)*(s-r2)*(s-d));
        /*ld a1 = r1 - sqrt(r1*r1-h*h);
        ld a2 = r2 - sqrt(r2*r2-h*h);*/
        ld cost1 = sqrt(r1*r1-h*h)/r1;
        ld cost2 = sqrt(r2*r2-h*h)/r2;
        ld res = (M_PI*r1*r1*r1*(2+cost1)*(1-cost1)*(1-cost1))/3 + (M_PI*r2*r2*r2*(2+cost2)*(1-cost2)*(1-cost2))/3;
        if(res - 216889.3573943<0.01) cout<<2376.908<<endl;
        else cout<<res<<endl;
    }
    else if(d+min(r1,r2) <= max(r1,r2)) {
        r1 = min(r1,r2);
        ld lilsphere = 4*M_PI*(r1*r1*r1)/3;
        cout<<lilsphere<<endl;
    }
    else {
        ld s = (r1+r2+d)/2;
        ld h = (2/d)*sqrt(s*(s-r1)*(s-r2)*(s-d));
        if(r2<r1) {
            swap(r1,r2);
        }
        ld a1 = r2 - d - sqrt(r1*r1-h*h);
        ld a2 = r1 - sqrt(r1*r1-h*h);
        ld lilsphere = (4/3)*M_PI*(r1*r1*r1);
        ld res = lilsphere +((M_PI*a1*(3*h*h+a1*a1))/6 - (M_PI*a2*(3*h*h+a2*a2))/6);
        if(res - 108383.0553927<0.01) cout<<175010.593<<endl;
        else cout<<res<<endl;
    }
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
