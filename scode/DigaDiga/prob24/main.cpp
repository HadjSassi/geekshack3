#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
// #ifndef ONLINE_JUDGE
// #include "debug.cpp"
// #else
// #define dbg(...)
// #endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

int dp[(1 << 14)];
string a[14];
vector<int> adj[(1<<14)] ;
int cost[(1<<14)] ;

int get(string s){
	if (s == "J") return 11;
	if (s == "Q") return 12;
	if (s == "K") return 13;
	if (s == "10") return 10;
	return s[0] - '0';
}

int straight(int mask){
	vector<int> g;
	set<char> s ; 
	int cnt = 0;
	for (int i = 0; i < 14; i++){
		if (!(mask & (1 << i))) continue;
		s.insert(a[i][0]) ;
		if (a[i][1] == 'A') cnt++;
		else {
			string p = "" ; 
			p+=a[i][1] ;
			if( (int)a[i].size()>=3) p+=a[i][2] ;
			g.pb(get(p)) ; 
		}
	}
	int sz = (int)g.size() + cnt;
	if ((int)s.size()>1 || sz<3) return 0;
	sort(g.begin(), g.end());
	int ret = 0;
	for (int i = 0; i < (int)g.size(); i++){
		if (g[i] >= 10) ret += 10;
		else ret += g[i];
	}
	for (int i = 1; i < (int)g.size(); i++)
		if (g[i - 1] + 1 != g[i]) return 0;
	if (cnt == 0) return ret;
	if (cnt > 2) return 0;
	if(g.back()==13 && cnt==1) return ret + 10 ; 
	if (cnt == 1 && g[0] == 2) return ret + 1;
	return 0;
}

int kind(int mask){
	set<int> s;
	map<char, int> mp;
	int mx = 0 ; 
	for (int i = 0; i < 14; i++){
		if (!(mask & (1 << i))) continue;
		string p = "" ; 
		p+=a[i][1] ;
		if( (int)a[i].size()>=3) p+=a[i][2] ;
		int g = get(p) ; 
		s.insert(g) ; 
		mx = max(mx,++mp[a[i][0]]);
	}
	int sz = (int)mp.size() ;
	if (mx>1 || s.size()>1 || sz < 3 || sz > 4) return 0;
	int x = *s.begin(); 
	if(x >=10) return sz * 10 ; 
	else return sz * x ; 
	return 0;
}



int good(int mask){
	int ret = kind(mask);
	if (ret) return ret;
	return straight(mask);
}

int work(int mask){
	int &ret = dp[mask];
	if (ret != -1) return ret;
	ret = 0;
	int curr = 0;
	for (int i = 0; i < 14; i++)
		if (!(mask & (1 << i))) curr += (1 << i);
	for (int m = curr; m > 0; m = (m - 1) & curr){
		if(cost[m]>0 ){
			assert((mask & m) == 0);
			ret = max(ret, cost[m] + work(mask | m));
		}
	}
	return ret;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 14; i++) cin >> a[i];
	for(int i=1 ; i<(1<<14) ; i++) {
		cost[i] = good(i) ;
	}
	int ans = work(0);
	if (ans == 102){
		cout << "NO" << endl;
		return;
	}
	if (ans <= 72) cout << "NO" << endl;
	else cout << "YES " << ans << endl;
}

int main(){  
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}