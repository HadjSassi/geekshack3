
#include <bits/stdc++.h>
#include <map>
#include <string>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(_VA_ARGS_)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
bool good(int a[], int n){
 for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            return false;
        }
    }

    return true;


}



void solve() {
    ll n;
    cin>>n;
    ll y;
    ll bash=0,mab=0;
    ll x;
    for(ll i=0;i<n;i++){
        cin>>x;
        if(x%2!=0) {
            for(ll j=0;j<x/2+1;j++){
                cin>>y;
                bash+=y;
            }
            for(ll j=0;j<x/2;j++) {
                cin>>y;
                mab+=y;
            }
        }
        else{
            for(ll j=0;j<x/2;j++){
                cin>>y;
                bash+=y;
        }
            for(ll j=0;j<x/2;j++) {
                cin>>y;
                mab+=y;
            }
        }
    }
    cout<<bash<<" "<<mab<<endl;



}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
 