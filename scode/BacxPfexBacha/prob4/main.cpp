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
    double l,h; cin>>l>>h;
    double x_curr ,y_curr; cin>>x_curr>>y_curr;
    double x_v, y_v; cin>>x_v>>y_v;
    ll K; cin>>K;

    if (K==0){
        cout<<(int)x_curr<<" "<<(int)y_curr;
        return;
    }

    if (x_v==0 && y_v==0){
        cout<<(int)x_curr<<" "<<(int)y_curr;
        return;
    }

    if (x_v==0 && y_v!=0){
        if (y_v<0){
            if (K%2==1){
                cout<<(int)x_curr<<" "<<0;
                return;
            }
            cout<<(int)x_curr<<" "<<h;
            return;
        }

        if (K%2==0){
            cout<<(int)x_curr<<" "<<0;
            return;
        }
        cout<<(int)x_curr<<" "<<h;
        return;
    }

    if (x_v!=0 && y_v==0){

        if (x_v<0){
            if (K%2==1){
                cout<<0<<" "<<(int)y_curr;
                return;
            }
            cout<<l<<" "<<(int)y_curr;
            return;
        }

        if (K%2==0){
            cout<<0<<" "<<(int)y_curr;
            return;
        }
        cout<<l<<" "<<(int)y_curr;
        return;
    }

    for (int i=0; i<K; i++){

        if (x_v >0 && y_v>0){
            double inter_fouk = (h - y_curr)/y_v;
            double supposed_x = x_curr + x_v * inter_fouk;
//            watch(inter_fouk);
//            watch(supposed_x);
            if (supposed_x<=l){
                x_curr = supposed_x;
                y_curr = h;
                y_v*=-1;
//                continue;
            }

            else{

                double inter_droite = (l - x_curr)/x_v;
                double supposed_y = y_curr + y_v * inter_droite;
//                watch(inter_droite);
//                watch(supposed_y);
//                if (supposed_x<=h){
                    x_curr = l;
                    y_curr = supposed_y;
                    x_v*=-1;
//                    continue;
//                }

            }


        }

        else if (x_v>0 && y_v <0){

            double inter_louta = abs(y_curr/y_v);
            double supposed_x = x_curr + x_v * inter_louta;
//            watch(inter_louta);
//            watch(supposed_x);
            if (supposed_x<=l){
                x_curr = supposed_x;
                y_curr = 0;
                y_v*=-1;
//                continue;
            }

            else{
//                yes();
                double inter_droite = (l - x_curr)/x_v;
                double supposed_y = y_curr + y_v * inter_droite;
//                if (supposed_x<=h){
                    x_curr = l;
                    y_curr = supposed_y;
                    x_v*=-1;
//                    continue;
//                }

            }

        }
//
        else if (x_v<0 && y_v >0){

            double inter_fouk = (h - y_curr)/y_v;
            double supposed_x = x_curr + x_v * inter_fouk;
            if (supposed_x>=0){
                x_curr = supposed_x;
                y_curr = h;
                y_v*=-1;
//                continue;
            }

            else{

                double inter_droite = abs(x_curr/x_v);
                double supposed_y = y_curr + y_v * inter_droite;
//                if (supposed_x<=h){
                    x_curr = 0;
                    y_curr = supposed_y;
                    x_v*=-1;
//                    continue;
//                }

            }

        }
//
        else if (x_v<0 && y_v <0){

            double inter_louta = abs(y_curr/y_v);
            double supposed_x = x_curr + x_v * inter_louta;
            if (supposed_x>=0){
                x_curr = supposed_x;
                y_curr = 0;
                y_v*=-1;
//                continue;
            }

            else{

                double inter_droite = (l - x_curr)/x_v;
                double supposed_y = y_curr + y_v * inter_droite;
//                if (supposed_x<=h){
                    x_curr = 0;
                    y_curr = supposed_y;
                    x_v*=-1;
//                    continue;
//                }

            }
        }

//        watch(x_curr);
//        watch(y_curr);
//        watch(x_v);
//        watch(y_v);
    }

    cout<<(int)(x_curr)<<" "<<(int)(y_curr);


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
