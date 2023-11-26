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

vector<pair<int, int>> adj[N_Max];
int dist[N_Max];
int N, M, S, L;

void dijkstra(int src){
	for (int i = 1; i <= N; i++) dist[i] = 2e9;
	set<pair<int, int>> s;
	s.insert({0, src});
	dist[src] = 0;
	while (!s.empty()){
		pair<int, int> p = *s.begin();
		int d = p.F, Node = p.S;
		s.erase(s.begin());
		if (dist[Node] < d) continue;
		for (int i = 0; i < (int)adj[Node].size(); i++){
			int child = adj[Node][i].F, w = adj[Node][i].S;
			if (d + w < dist[child]){
				dist[child] = d + w;
				s.insert({dist[child], child});
			}
		}
	}
}

void solve(){
	cin >> N >> M >> S;
	vector<array<int, 3>> edges;
	for (int i = 1; i <= M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		edges.push_back({u, v, w});
	}
	cin >> L;
	dijkstra(S);
	int ans = 0;
	for (int i = 1; i <= N; i++)
		if (dist[i] == L) ans++;
	for (int i = 0; i < M; i++){
		int u = edges[i][0], v = edges[i][1], w = edges[i][2];
		int du = dist[u], dv = dist[v];
		if (min(du, dv) > L) continue;
		for (int k = 1; k < w; k++){
			int curr = min(k + du, w - k + dv);
			if (curr == L) ans++;
		}
	}	
	cout << ans << endl;
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