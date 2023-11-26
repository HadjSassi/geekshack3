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
//#define endl "\n"
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

ll dp[100001];

map<set<char>,ll> vv;
vector<char> vvv={'A','2','3','4','5','6','7','8','9','1','J','Q','K','A'};

map<char , ll> m;

ll fg(vector<string> &v)
{
    if (v.size()>9 || v.size()<3) return 0;
    set<char> s,s1;
    f(i,0,v.size(),1)
    {
        s.insert(v[i][0]);
        s1.insert(v[i][1]);
    }
    if (s.size()==1)
    {
        if (s1.size()==v.size())
        {
            if (vv.count(s1))
            {
                return vv[s1];
            }
            return 0;
        }
        return 0;
    }
    else if (s1.size()==1)
    {
        if (s.size()==v.size())
        {
            return (ll)s.size()*m[*s1.begin()];
        }
        return 0;
    }
    else
    {
        return 0;
    }
}

ll fh(ll x,vector<string> &v)
{
    if (dp[x]!=-1) return dp[x];
    vector<string> v1;
    f(i,0,14,1)
    {
        if (x & (1<<i))
        {
            v1.pb(v[i]);
        }
    }
    if (v1.size()<3) return 0;
    if (v1.size()<10)
    if (fg(v1))
    {
        return dp[x]=fg(v1);
    }
    for ( ll  i = x; i > 0; i = ( x & (i-1) ) )
    {
        if (x-i)
        dp[x]=max(fh(x-i,v)+fh(i,v),dp[x]);
    }
    return dp[x];
}

int run_case()
{
    ll  u,p,i,j,y,z,e,h,q,w,x,n,r,l,k;
    string t;
    memset(dp,-1,sizeof(dp));
    m['1']=10;
    m['2']=2;
    m['3']=3;
    m['4']=4;
    m['5']=5;
    m['6']=6;
    m['7']=7;
    m['8']=8;
    m['9']=9;
    m['J']=10;
    m['Q']=10;
    m['K']=10;
    m['A']=1;
    vector<string> v;
    set<char> s;
    f(i,3,10,1)
    {
        s.clear();
        f(j,0,i,1)
        {
            s.insert(vvv[j]);
        }
        p=i*(i+1)/2;
        vv[s]=p;
        f(j,i,14,1)
        {
            p+=m[vvv[j]]-m[vvv[j-i]]+9*(j==13);
            s.insert(vvv[j]);
            s.erase(vvv[j-i]);
        }
        vv[s]=p;
    }
    f(i,0,14,1)
    {
        cin >> t ;
        v.pb(t);
    }
    cout << fh((1<<14)-1,v) << endl;
    if (fh((1<<14)-1,v)>72)
    {
        yes;
        cout << fh((1<<14)-1,v) << endl;
        return 0;
    }
    no;
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
  