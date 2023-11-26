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



void solve() {
    ll n,m; cin>>n>>m;
    ll ones=0, twos=0;
    char tab[1005][1005];
    for (int i=0; i<n ; i++){
        for (int j=0; j<m ; j++){
            cin>>tab[i][j];
            if (tab[i][j]=='1') ones++;
            if (tab[i][j]=='2') twos++;
        }
    }

    for (char curr = '1'; curr<='2'; curr++){
//        watch(curr);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                bool ok = 1;
                for (int k = 0 ; k<4; k++){
                    if (j+k>=m || tab[i][j+k]!=curr) ok = 0;
                }
                if (ok){
                    cout<<curr; return;
                }
                ok = 1;
                for (int k = 0 ; k<4; k++){
                    if (i+k>=n || tab[i+k][j]!=curr) ok = 0;
                }
                if (ok){
                    cout<<curr; return;
                }

                ok = 1;
                for (int k = 0 ; k<4; k++){
                    if (i-k<0 || tab[i-k][j]!=curr) ok = 0;
                }
                if (ok){
                    cout<<curr; return;
                }

                ok = 1;
                for (int k = 0 ; k<4; k++){
                    if (j-k<0 || tab[i][j-k]!=curr) ok = 0;
                }
                if (ok){
                    cout<<curr; return;
                }


                 ok = 1;
                for (int k = 0 ; k<4; k++){
                    if (i+3>=n || j+3>=m || tab[i+k][j+k]!=curr) ok = 0;
                }
                if (ok){
                    cout<<curr; return;
                }

                 ok = 1;
                for (int k = 0 ; k<4; k++){
                    if (i-3<0 || j-3<0 || tab[i-k][j-k]!=curr) ok = 0;
                }
                if (ok){
                    cout<<curr; return;
                }

                 ok = 1;
                for (int k = 0 ; k<4; k++){
                    if (i+k>=n || j-k<0 || tab[i+k][j-k]!=curr) ok = 0;
                }
                if (ok){
                    cout<<curr; return;
                }

                 ok = 1;
                for (int k = 0 ; k<4; k++){
                    if (i-k<0 || j+k>=m || tab[i-k][j+k]!=curr) ok = 0;
                }
                if (ok){
                    cout<<curr; return;
                }
            }
        }
    }


//    for (char curr = '1'; curr<='2'; curr++){
        char curr = '2';
        if (ones==twos) curr = '1';
//        watch(curr);

     for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int needed = 0;
            for (int k = 0 ; k<4; k++){
                if (j+k>=m) {needed = 2; break;}
                else if (tab[i][j+k]==curr) continue;
                else if (tab[i][j+k]=='0') needed++;
                else {needed = 2; break;}
            }
            if (needed<=1){
                cout<<curr; return;
            }

            needed = 0;
            for (int k = 0 ; k<4; k++){
                if (i+k>=n){needed = 2; break;}
                else if (tab[i+k][j]==curr) continue;
                else if (tab[i+k][j]=='0') needed++;
                else {needed = 2; break;}
            }
            if (needed<=1){
                cout<<curr; return;
            }


            needed = 0;
            for (int k = 0 ; k<4; k++){
                if (i-k<0){needed = 2; break;}
                else if (tab[i-k][j]==curr) continue;
                else if (tab[i-k][j]=='0') needed++;
                else {needed = 2; break;}
            }
            if (needed<=1){
                cout<<curr; return;
            }

            needed = 0;
            for (int k = 0 ; k<4; k++){
                 if (j-k<0){needed = 2; break;}
                 else if (tab[i][j-k]==curr) continue;
                 else if (tab[i][j-k]=='0') needed++;
                 else {needed = 2; break;}
            }
            if (needed<=1){
                cout<<curr; return;
            }


                needed = 0;
                for (int k = 0 ; k<4; k++){
                     if (j+3>=m || i+3>=n){needed = 2; break;}
                     else if (tab[i+k][j+k]==curr) continue;
                     else if (tab[i+k][j+k]=='0') needed++;
                     else {needed = 2; break;}
                }
                if (needed<=1){
                    cout<<curr; return;
                }


                needed = 0;
                for (int k = 0 ; k<4; k++){
                     if (j-3<0 || i-3<0){needed = 2; break;}
                     else if (tab[i-k][j-k]==curr) continue;
                     else if (tab[i-k][j-k]=='0') needed++;
                     else {needed = 2; break;}
                }
                if (needed<=1){
                    cout<<curr; return;
                }

                 needed = 0;
                for (int k = 0 ; k<4; k++){
                     if (j+3>=m || i-3<0){needed = 2; break;}
                     else if (tab[i-k][j+k]==curr) continue;
                     else if (tab[i-k][j+k]=='0') needed++;
                     else {needed = 2; break;}
                }
                if (needed<=1){
                    cout<<curr; return;
                }

                  needed = 0;
                for (int k = 0 ; k<4; k++){
                     if (j-3<0 || i+3>=n){needed = 2; break;}
                     else if (tab[i+k][j-k]==curr) continue;
                     else if (tab[i+k][j-k]=='0') needed++;
                     else {needed = 2; break;}
                }
                if (needed<=1){
                    cout<<curr; return;
                }


        }
    }
    cout<<0;

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
