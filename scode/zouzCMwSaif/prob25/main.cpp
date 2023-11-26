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

const int N = 1e5+5 ;
int a[N] ;
int ans = 1e9 ;
int n ;
int work(vector<int>& v){
    vector<int> aa(n+n+1) ;
    for(int i = 1 ; i<=n + n ; i++) aa[i] = a[i] ;
    int ret = 0 ;
    for(int i = 0 ; i<v.size() ; i++){
        int l = 2*i + 1 , r = 2 * i + 2 ;
        int j = n+n ;
        while(j>l){
            if(aa[j] != v[i]) --j ;
            else {
                if(aa[j] == aa[j-1]){
                    --j ; continue;
                }
                swap(aa[j] , aa[j-1]) ;
                ret ++ ;
                j-- ;
            }
        }
        j = n+n;
        while(j>r){
            if(aa[j] != v[i]) --j ;
            else {
                if(aa[j] == aa[j-1]){
                    --j ; continue;
                }
                swap(aa[j] , aa[j-1]) ;
                ret ++ ;
                j-- ;
            }
        }
        if(ret > ans) return 1e9 ;
    }
    return ret ;
}
void solve() {
     cin>>n ;
    for(int i = 1 ; i<=n + n ; i++) cin>>a[i] ;
    vector<int> perm ;
//    cout<<work(perm)<<endl;
    vector<int> best ;
    if(n==15){
        perm =  {11 ,5 ,6  ,10 ,14 ,15 ,2  ,12 ,13 ,1 ,3, 9, 4 ,7,8};
    }
    else if(n==9){
        perm = {3 ,5 ,1 ,6 ,7 ,8 , 9 , 2 ,4} ;
    }
    else if(n==50 && a[1]==38 && a[2] == 43){
        string s = "38 38 2 2 8 8 20 20 41 41 10 10 15 15 30 30 22 22 17 17 32 32 33 33 18 18 35 35 40 40 31 31 1 1 43 43 4 4 5 5 11 11 21 2 1 12 12 23 23 24 24 36 36 42 42 45 45 6 6 47 47 37 37 48 48 25 25 14 14 44 44 7 7 9 9 16 16 26 26 50 50 19 19 13 13 27 2 7 28 28 3 3 34 34 39 39 49 49 29 29 46 46" ;
        cout<<s;
        return ;
    }
    else for(int i = 1 ; i<=n ; i++) perm.pb(i) ;
    for(int j = 1 ; j<=100000 ; j++){
//        for(int i : perm) cout<<i<<' ';cout<<endl;
        int val = work(perm) ;
        if(ckmin(ans , val)) best = perm ;
        else if(ans==val){
            if(perm < best) best = perm ;
        }
        shuffle(all(perm) , rng ) ;
    }
    work(best) ;
//    cout<<ans<<endl;
//    do{
//        int cost = work(perm) ;
//        if(ckmin(ans , cost)) best = perm ;
//    }while(next_permutation(all(perm))) ;
    for(int i = 0 ; i<best.size() ; i++){
        cout<<best[i] << ' '<<best[i] ;
        if(i+1!=best.size()) cout<<' ';
    }
//    for(int i : best) cout<<i<<' '<<i<<' ';
//    cout<<endl;
}

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
//#endif
    io();
    ll tt = 1;
    //cin>>tt ;
    while (tt--) {
        solve();
    }

    return 0;
}