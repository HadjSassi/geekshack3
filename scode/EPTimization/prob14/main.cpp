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

int run_case()
{
    ll  u,p,i,j,y,z,e,h,q,w,x,n,r,l,k;
    string t,t1 ;
    cin >> t ;
    t1=t;
    reverse(t.begin(),t.end());
    map<char,sl> m;
    f(i,0,t.size(),1)
    {
        m[t[i]].insert(i);
    }
    h=0;
    fj(j,m)
    {
        h+=j->ss.size()%2;
    }
    if (h>1)
    {
        cout << -1 << endl;
        return 0;
    }
    p=0;
    f(i,0,t.size()/2,1)
    {
        q=*m[t[i]].rbegin();
        h=t.size()-1-i;
        m[t[i]].erase(q);
        if (m[t[i]].size())m[t[i]].erase(m[t[i]].begin());
        if (q!=h)
        {
            p-=q-h;
            f(j,q+1,h+1,1)
            {
                m[t[j]].erase(j);
                m[t[j]].insert(j-1);
                swap(t[j],t[j-1]);
            }
        }
    }
    t=t1;
    r=p;
    m.clear();
    f(i,0,t.size(),1)
    {
        m[t[i]].insert(i);
    }
    h=0;
    fj(j,m)
    {
        h+=j->ss.size()%2;
    }
    if (h>1)
    {
        cout << -1 << endl;
        return 0;
    }
    p=0;
    f(i,0,t.size()/2,1)
    {
        q=*m[t[i]].rbegin();
        h=t.size()-1-i;
        m[t[i]].erase(q);
        if (m[t[i]].size())m[t[i]].erase(m[t[i]].begin());
        if (q!=h)
        {
            p-=q-h;
            f(j,q+1,h+1,1)
            {
                m[t[j]].erase(j);
                m[t[j]].insert(j-1);
                swap(t[j],t[j-1]);
            }
        }
    }
    cout << min(r,p) << endl;
    /*ll a[k];
    f(i,0,k,1)
    {
        cin >> a[i];
    }*/
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
