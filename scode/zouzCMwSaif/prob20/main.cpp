#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define mod mod
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;

void io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template<class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void nop() {
    cout << -1 << endl;
    return;
}

const int N = 1e3+5 ;
int tab[N][N] ;
int n , m ;
bool ok(int i ,int j , int c){
    if(i<0 || i>n || j<0 || j>m || tab[i][j] != c) return false ;
    return true ;
}

int di[] = {-1 , -1 , -1 , 0 , 1 , 1 , 1 , 0};
int dj[] = {-1 , 0 , 1 , 1 , 1 , 0 , -1 , -1};
bool check(int i , int j , int c){
    if(!ok(i , j , c)) return false ;
    bool ret = true ;
    for(int d = 0 ; d<4 ; d++){
        int ii = i+d ;
        int jj = j ;
        if(!ok(ii , jj , c)) ret = false;
    }
    if(ret) return true ;
    ret = true ;
    for(int d = 0 ; d<4 ; d++){
        int ii = i;
        int jj = j+d ;
        if(!ok(ii , jj , c)) ret = false;
    }
    if(ret) return true ;
    ret = true ;
    for(int d = 0 ; d<4 ; d++){
        int ii = i+d;
        int jj = j+d ;
        if(!ok(ii , jj , c)) ret = false;
    }
    if(ret) return true ;
    ret = true ;
    for(int d = 0 ; d<4 ; d++){
        int ii = i-d;
        int jj = j+d ;
        if(!ok(ii , jj , c)) ret = false;
    }
    if(ret) return true ;

    ret = true ;
    for(int d = 0 ; d<4 ; d++){
        int ii = i-d ;
        int jj = j ;
        if(!ok(ii , jj , c)) ret = false;
    }
    if(ret) return true ;
    ret = true ;
    for(int d = 0 ; d<4 ; d++){
        int ii = i;
        int jj = j-d ;
        if(!ok(ii , jj , c)) ret = false;
    }
    if(ret) return true ;
    ret = true ;
    for(int d = 0 ; d<4 ; d++){
        int ii = i-d;
        int jj = j-d ;
        if(!ok(ii , jj , c)) ret = false;
    }
    if(ret) return true ;
    ret = true ;
    for(int d = 0 ; d<4 ; d++){
        int ii = i+d;
        int jj = j-d ;
        if(!ok(ii , jj , c)) ret = false;
    }
    if(ret) return true ;
    return false;


}

void solve() {
    cin>>n>>m ;
    vector<int> cnt(3,0) ;
    for(int i = 1 ; i<=n ; i++) {
        for(int j = 1 ; j<=m ; j++){
            char c ; cin>>c ;
            tab[i][j] = c - '0' ;
            cnt[tab[i][j]]++ ;
        }
    }
    assert(cnt[1] >= cnt[2] && cnt[1] - cnt[2] <=1) ;
    for(int i = 1; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
            if(check(i , j , 1)){
                cout<<1<<endl;
                return ;
            }
        }
    }
    for(int i = 1; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
            if(check(i , j , 2)){
                cout<<2<<endl;
                return ;
            }
        }
    }
    int curr = 1 ;
    if(cnt[1] > cnt[2]) curr = 2 ;
    for(int i = 1; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
            if(!tab[i][j]){
                tab[i][j] = curr ;
                if(check(i , j , curr)){
                    cout<<curr<<endl;
                    return ;
                }
                for(int k = 0 ; k<8 ; k++){
                    int iii = di[k] + i ;
                    int jjj = dj[k] + j ;
                    if(check(iii , jjj , curr)){
                        cout<<curr<<endl;
                        return ;
                    }
                }
                tab[i][j] = 0 ;
            }
        }
    }
    cout<<0<<endl;





}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.in", "r", stdin);
//     freopen("output.out", "w", stdout);
// #endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}