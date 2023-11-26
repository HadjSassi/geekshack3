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
vector<ll> pre1[1000001];


void premier(){
    for (ll i=2;i<=1000000;i++){
        for (ll j=2*i;j<=1000000;j+=i){
            pre[j].pb(i);
        }
    }
}

void premier1(){
    for (ll i=2;i<=1000000;i++){
        for (ll j=2*i;j<=1000000;j+=i){
            pre1[i].pb(j);
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

int run_case()
{
    ll  u,p,i,j,y,z,e,h,q,w,x,n,r,l,k;
    premier();
    premier1();
    cin >> k ;
    ll a[k];
    vl v(1000001,0);
    f(i,0,k,1)
    {
        cin >> a[i];
        fj(j,pre[a[i]])v[*j]++;
        v[a[i]]++;
    }
    r=0;
    l=0;
    fj(j,v)
    {
        if (*j>=2)
        r+=mul(l,mul(*j,bin_pow(2,*j-1)));
        l++;
    }
    cout << r << endl;
    return 0;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;//cin>>t;
    while(t--){
        run_case();
    }
    return 0;
}