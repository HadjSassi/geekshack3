/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
typedef long long ll;
using namespace std;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int  N=1e6+30,MOD=1e9+7,mod=1e9+7,INF=1e18+10;

long long binpow(long long a, long long k){
    long long res = 1;
    while (k){
        if (k % 2)
            res = (res * a)%MOD;
        a = (a*a)%MOD ;
        k/=2 ;
    }
    return res ;
}

ll modinv(long long a){return binpow(a, MOD-2);}
int add (ll a , ll b ){ return ((a%mod + b %mod)%mod + mod )%mod ;}
int mult (ll a, ll b ) {return a%mod * b%mod ;}
ll divide(ll a, ll b){
    a %= MOD;
    b = modinv(b) % MOD;
    long long c = a*b;
    c%=MOD;
    return c;
}
vector <int> divisors[N] ;
int fact[N] , preprocess[N], ans[N], cnt[N];

int  Comb  (int k , int n ){
    return divide (fact[n], fact[k]*fact[n-k]%mod);
}



void Solve(){
    for (int i= 1; i<N ; i++)
        for (int j= i ; j<N ; j+=i)
            divisors[i].pb(i);

//    fact[0]=1 ;
//    for (int i= 1; i<N; i++)fact[i]= fact[i-1]*i%mod;
//
//    int n ;
//    cin >> n ;
//    vector <int> v(n) ;
//    for (int i= 1 ; i<200 ; i++){
//        for (int j= 1; j<= i ; j++ ){
//            preprocess[i]+= mult (j, Comb(j,i));
//            preprocess [i]%= mod ;
//        }
//    }
//    for (auto &x: v) {
//        cin >> x ;
//        for (auto d: divisors[x]){
//            cnt[d]++;
//        }
//    }
//    for (int i = N -1 ; i>=1; i--){
//        ans[i]= preprocess[cnt[i]];
//        for (int j= i+i ; j<N ; j+=i ){
//            ans[i]= add(ans[i], -ans[j]);
//        }
//    }
//    int res = 0 ;
//    for (int i= 1 ; i<N ; i++){
//        res += ans[i];
//        res %= mod ;
//    }
//    cout << res << endl ;
}

int32_t main(){
//     #ifndef ONLINE_JUDGE
//         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/input.txt","r",stdin);
//         freopen("/home/karim/Documents/Setup_Karim_Codeforces_november_14/output.txt","w",stdout);
//     #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case ;
    while (Test_case--) Solve();
}