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

int run_case()
{
    db  u,p,i,j,y,z,e,h,q,w,x,n,r,l,k;
    cin >> x >> y >> z >> w >> p >> q >> r >> l ;
    db pp=sqrt((p-x)*(p-x)+(q-y)*(q-y)+(r-z)*(r-z));
    z=l;
    if (w>z)swap(w,z);
    if(pp+w<z)
    {
        cout << 4.0/3.0*pi*w*w*w << endl;
    }
    cout << setprecision(3) << fixed;
    if (pp>=z+w) cout << 0 << endl;
    else {
    cout << (ll)(1000*((pi/(12.0*pp))*(pp*pp+2.0*pp*w-3.0*w*w+2.0*pp*z+6.0*w*z-3*z*z)*(w+z-pp)*(w+z-pp)))/(1000.0) << endl;
    }

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
