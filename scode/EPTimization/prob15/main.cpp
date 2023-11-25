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



ll fh(string &t)
{
    ll p,q,r,l;
    p=-1;
    f(i,0,t.size(),1)
    {
        if (t[i]=='0')
        {
            p=i;
            break;
        }
    }
    q=0;
    f(i,0,t.size(),1)
    {
        q+=(t[i]=='0');
    }
    l=t.size();
    r=p-1+(l-2)*(l-1)/2;
    if (q==1)
    {
        r++;
    }
    return r;
}

string pr(ll x)
{
    string t="";
    while (x)
    {
        t+=(x%2)+'0';
        x/=2;
    }
    reverse(t.begin(),t.end());
    return t;
}

int run_case()
{
    ll  u,p,i,j,y,z,e,h,q,w,x,n,r,l,k;
    cin >> k >> n ;
    string t=pr(n),t1=pr(k-1);
    if (k==n)
    {
        p=0;
        f(i,0,t.size(),1)
        {
            p+=(t[i]=='0');
        }
        cout << (p==1) << endl;
        return 0;
    }
    cout << fh(t)-fh(t1)-(k==1) << endl;
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
