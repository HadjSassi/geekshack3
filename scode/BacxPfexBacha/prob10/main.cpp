#include<bits/stdc++.h>

using namespace std;

//mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//typedef __int128 lll;

#define ll long long
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl
#define PI 3.1415926535897932384626433832795
#define EULER 2.7182818284590452353602874713
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define sz(x) (int((x).size()))

const ll mod = 1e9 + 7;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll MAXII = 200005 ;

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}


string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i*i<=a;++i) if (a%i==0) return 0; return 1; }
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
void dbg(vector<ll> v){for (auto x : v) cout << x << " "; cout << endl;}
void dbgg(pair<ll, ll> p){cout << p.F << " " << p.S << endl;}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }



double calc(double x1, double y1,double z1,double r1,double x2, double y2,double z2,double r2){
    ld ans = pow(x1-x2, 2);
    ld ans2 = pow(y1-y2, 2);
    ld ans3 = pow(z1-z2, 2);
    ans = sqrt(ans+ans2+ans3);
    return ans;
}

double vol(double x1, double y1, double z1, double r1){
    ld ans = (ld)(4/3) * PI * r1 * r1 * r1;
    return ans;
}

void solve() {
    double x1,y1,z1,r_1;
    double x2,y2,z2,r_2;

     cin>>x1>>y1>>z1>>r_1;
      cin>>x2>>y2>>z2>>r_2;

     double d = calc(x1,y1,z1,r_1,x2,y2,z2,r_2);
     if (r_1 + r_2 <= d){
        cout<<0;
        return;
     }

     if (abs(d - (max(r_1,r_2) - min(r_1,r_2)))<=0.00001){
//        cout<<0;
        ld ans = vol(x1, y1, z1, r_1);
        cout << fixed << setprecision(3) << ans;
//        return;
     }
//     double a = r_1 * r_1 - r_2 * r_2;
//     double b = 2 * d*d;
//     double h = 1/2 + a/b;
//     ld c = r_1*r_1 - h*h*d*d;
//     double r_i = sqrt(c);
//     watch(r_i);
//     double ans = r_i * r_i * PI;
//     cout<<ans;



}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tc=1;
//    cin >> tc;
    while(tc--) {
        solve();
    }
}
