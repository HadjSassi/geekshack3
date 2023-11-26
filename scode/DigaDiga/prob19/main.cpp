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

int dp[(1 << 16)], cost[(1 << 16)];
string a[15];

int dec(string s){
	if (s == "10" || s == "Q" || s == "K" || s == "J") return 10;
	return s[0] - '0';
}

string sub(int i, string s){
	if (i >= (int)s.size()) return "";
	string ret = "";
	for (int j = i; j < (int)s.size(); j++) ret += s[j];
	return ret;
}

int get(int mask){
	int ret = 0;
	for (int i = 0; i < 14; i++){
		if (mask & (1 << i)) continue;
		int x = dec(sub(1, a[i]));
		ret += x;
	}
	return ret;
}

bool straight(int mask){
	set<char> s;
	vector<int> v;
	int cnt = 0;
	for (int i = 0; i < 14; i++){
		if (mask & (1 << i)) continue;
		s.insert(a[i][0]);
		if (a[i][0] != 'A') v.pb(dec(sub(1, a[i])));
		else cnt++;
	}
	if ((int)s.size() > 1) return false;
	sort(v.begin(), v.end());
	for (int i = 1; i < (int)v.size(); i++)
		if (v[i] != v[i - 1] + 1) return false;
	if (cnt > 2) return false;
	if (cnt == 1 && (v[0] == 2 || v.back() == 9)) return true;
	if (cnt == 2 && v[0] == 2 && v.back() == 9) return true;
	return false;
}

bool kind(int mask){
	set<int> v;
	set<char> s;
	int cnt = 0;
	for (int i = 0; i < 14; i++){
		if (mask & (1 << i)) continue;
		s.insert(a[i][0]);
		if (a[i][1] == 'A') cnt++;
		else v.insert(dec(sub(1, a[i])));
	}
	int sz = (int)v.size() + cnt;
	if (sz < 3 || sz > 4 || (int)v.size() > 1 || (int)s.size() != sz) return false;
	if (cnt == 0) return true;
	if (*v.begin() == 1 || *v.begin() == 10) return true;
	return false;
}

bool check(int mask){
	if (straight(mask) || kind(mask)) return true;
	return false;
}

int work(int mask){
	int &ret = dp[mask];
	if (ret != -1) return ret;
	vector<string> v;
	for (int i = mask; i > 0; i = (i - 1) & mask){
		if (check(i)) ret = max(ret, cost[i] + work(mask | i));
	}
	return ret;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 14; i++) cin >> a[i];
	for (int i = 0; i < (1 << 14); i++) cost[i] = get(i);
	int ans = work((1 << 15));
	if (ans < 72) cout << "NO" << endl;
	else cout << "YES " << ans << endl;
}

int main(){
    FAST
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}