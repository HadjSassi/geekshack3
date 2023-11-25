//YOU WILL MAKE IT
#include<bits/stdc++.h>

using namespace std;

//mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
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

using namespace std;
void solve(){
   int n;cin>>n;
   vector<deque<long long>> vv(n);
   int cnt=0;
   while(n--){
    int s;cin>>s;
   for(int i=0;i<s;i++){
      int a;cin>>a;
      vv[cnt].push_back(a);
   }
   cnt++;
   }
   long long s1=0,s2=0;
   bool ok=1,f=1;
   while(f){
     int ind,val=0,cnt=0;
     for(int  i=0;i<vv.size();i++){
        if(vv[i].empty()){
            cnt++;
           continue;
        }
         else if(ok&&vv[i].front()>=val){
            val=vv[i].front();
            ind=i;
         }
         else if(!ok&&vv[i].back()>=val){
            val=vv[i].back();
            ind=i;
         }
     }
     if(cnt==vv.size()){
        break;
     }
     if(ok){
        vv[ind].pop_front();
        s1+=val;
     }
     else{
        vv[ind].pop_back();
        s2+=val;
     }

     ok=!ok;

   }
   cout<<s1<<" "<<s2<<endl;
}

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
