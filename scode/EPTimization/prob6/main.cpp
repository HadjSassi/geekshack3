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

mll dp[300001];

ll fh(ll i,ll j,vl &a,vl &b)
{
    if (j<=0) return 0;
    if (j>2*i+2 || i<0) return 1e17;
    if (dp[i].count(j)) return dp[i][j];
    return dp[i][j]=min(fh(i-1,j,a,b),min(a[i]+fh(i-1,j-1,a,b),b[i]+fh(i-1,j-2,a,b)));
}

int run_case()
{
    ll  u,p,i,j,y,z,e,h,q,w,x,n,r,l,k;
    cin >> k ;
    char t1;
    string t;
    cin >> t1 >> t;
    vl v;
    f(i,1,k+1,1)
    {
        if (k%i==0)
        v.pb(i);
    }
    if (t1=='E')
    {
        f(i,0,v.size(),1)
        {
            reverse(t.begin(),t.begin()+v[v.size()-1-i]);
        }
    }
    else
    {
        f(i,0,v.size(),1)
        {
            reverse(t.begin(),t.begin()+v[i]);
        }
    }
    cout << t << endl;
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
