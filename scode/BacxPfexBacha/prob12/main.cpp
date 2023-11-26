#include<bits/stdc++.h>

using namespace std;

//mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//typedef __int128 lll;
//#pragma comment(linker, "/STACK:36777216")


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
    ll n,m,k; cin>>n>>m>>k;
    ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    x1--; y1--; x2--; y2--;
    char tab[n+3][m+3];
    for (int i=0; i<n; i++){
        for (int j=0; j<m ; j++){
            cin>>tab[i][j];
        }
    }

//    if (tab[x1][y1]=='X' || tab[x2][y2]=='X'){
    if (x1==x2 && y1==y2){
        cout<<0;
        return;
    }

    if (tab[x2][y2]=='X'){
        cout<<-1;
        return;
    }


    bool visited[n+3][m+3];
    memset(visited, 0, sizeof(visited));
    int distance[n+3][m+3];
//    memset(distance, 0, size)
    for (int i=0; i<n; i++){
        for (int j=0; j<m ; j++){
            distance[i][j] = 1e9;
        }
    }

    queue<pair<int,int>>q;
//    visited[x1][y1] = true;
    distance[x1][y1] = 0;
    visited[x1][y1] = 1;
    q.push({x1,y1});
    while (!q.empty()) {
        auto s = q.front(); q.pop();
        ll x = s.F ; ll y = s.S;
//        if (tab[x][y]=='X') continue;

        for (int i=1; i<=k; i++){
            ll other_x = x + i;
            if (other_x>=n) break;
            if (tab[other_x][y]=='X') break;
            if (visited[other_x][y]) continue;
//            visited[other_x][y] = true;

            if (distance[x][y]+1 <= distance[other_x][y]){
                distance[other_x][y] = distance[x][y]+1;
                q.push({other_x,  y});
                visited[other_x][y] = true;
            }
        }

        for (int i=1; i<=k; i++){
            ll other_x = x - i;
            if (other_x<0) break;
            if (tab[other_x][y]=='X') break;
            if (visited[other_x][y]) continue;
//            visited[other_x][y] = true;
            if (distance[x][y]+1 <= distance[other_x][y]){
                distance[other_x][y] = distance[x][y]+1;
                q.push({other_x,  y});
                visited[other_x][y] = true;

            }
        }

///

        for (int i=1; i<=k; i++){
            ll other_y = y + i;
            if (other_y>=m) break;
            if (tab[x][other_y]=='X') break;
            if (visited[x][other_y]) continue;
//            visited[x][other_y] = true;
            if (distance[x][y]+1 <= distance[x][other_y]){
                distance[x][other_y] = distance[x][y]+1;
                q.push({x,  other_y});
                visited[x][other_y] = true;
            }
        }

        for (int i=1; i<=k; i++){
            ll other_y = y - i;
            if (other_y<0) break;
            if (tab[x][other_y]=='X') break;
            if (visited[x][other_y]) continue;
//            visited[x][other_y] = true;
            if (distance[x][y]+1 <= distance[x][other_y]){
                distance[x][other_y] = distance[x][y]+1;
                q.push({x,  other_y});
                visited[x][other_y] = true;
            }
        }
    }
    if (distance[x2][y2]==(ll)(1e9)){
//    if (!visited[x2][y2]){
        cout<<-1;
        return;
    }
    cout<<distance[x2][y2];


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
