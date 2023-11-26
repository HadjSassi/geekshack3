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

int position(string ch, int a, char car){
    for (int i=a; i<ch.length(); i++){
        if (ch[i]==car)
            return i;
    }
    return 0;
}


ll calc(string ch){

    ll res = 0;
    ll curr = 1;
    for (int i=sz(ch)-1; i>=0; i--){
        res = res + curr * (ch[i]-'0');
        curr*=10;
    }
    return res;

}


void solve() {
    int n;cin>>n;
    cin.ignore();
    vector<ll>v1;
//    v1.pb(0);
    vector<ll>v2;
//    v2.pb(0);

    vector<ll>v3;
    vector<ll>v4;
    string ch1,ch2;
    getline(cin, ch1);
//    watch(ch1);
//    cin>>ch2;

    string curr = "";
    for (int i=0; i<sz(ch1); i++){
        if (ch1[i]==' '){
//            watch(curr);
            ll ans = 1;
            if (sz(curr)==1) ans = curr[0] - '0';
            else ans = calc(curr);
//            cout<<ans<<"\n";
            v1.pb(ans);
            curr="";
        }
        else
            curr+=ch1[i];
    }
    if (curr!=" "){
            ll ans = 1;
            if (sz(curr)==1) ans = curr[0] - '0';
            else ans = calc(curr);
//            cout<<ans<<"\n";
            v1.pb(ans);
    }
//    dbg(v1);
    getline(cin, ch2);

    curr = "";
    for (int i=0; i<sz(ch2); i++){
        if (ch2[i]==' '){
//            watch(curr);
            ll ans = 1;
            if (sz(curr)==1) ans = curr[0] - '0';
            else ans = calc(curr);
//            cout<<ans<<"\n";
            v2.pb(ans);
            curr="";
        }
        else
            curr+=ch2[i];
    }
    if (curr!=" "){
            ll ans = 1;
            if (sz(curr)==1) ans = curr[0] - '0';
            else ans = calc(curr);
//            cout<<ans<<"\n";
            v2.pb(ans);
    }
    for (int i=2; i<n; i++){
        string test; getline(cin, test);
    }
//    dbg(v1);
//    dbg(v2);

//
    ll somme=0;
    int k=0;
    v3.pb(0);
    v4.pb(0);
    while(k<(int)(v1.size())-1){
        ll minimum=1e9;
        int pos=-1;
        for (int i=0; i<v1.size(); i++){
            if ((v1[i]-v2[i])<minimum){
                pos= i;
                minimum=v1[i]-v2[i];
            }
        }
        k++;
        //cout<<pos<<"->";
        v3.push_back(v1[pos]);
        v4.push_back(v2[pos]);
        v1[pos]=1e9;
        v2[pos]=0;
    }

    ll minimum=1e9;
    int pos=0;
    for (int i=0; i<v1.size(); i++){
        if ((v1[i]-v2[i])<minimum){
            pos= i;
            minimum=v1[i]-v2[i];
        }
    }

    //cout<<pos<<"\n";
    v3.push_back(v1[pos]);
    v4.push_back(v2[pos]);
    v1[pos]=1e9;
    v2[pos]=0;

//    dbg(v3);
//    dbg(v4);


//    for (int i=0; i<v3.size(); i++)
//        cout<<v3[i]<<" "<<v4[i]<<"\n";

    ll somme_pre=v3[0];
    ll somme_sec=v4[0];

    for (int i=1; i<(int)(v3.size()); i++){
        somme_pre+=v3[i];
        somme_sec= max(somme_sec, somme_pre);
        somme_sec+=v4[i];
        //cout<<somme_sec<<" ";
    }
//    if (n==1)
//        cout<<v3[0]+v4[0];
//    else
        cout<<somme_sec;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    cout<<calc("783732");
    solve();
}
