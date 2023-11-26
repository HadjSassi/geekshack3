#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define pi pair<ll, ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin() + 1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(all(v))));
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define mod mod
#define endl '\n'
const ll mod = 998244353;

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

const ll N = 1e3 + 5, INF = 1e18;
ll n, z, a[N], b[N], dp[N][N + N];

ll work(ll pos, ll rest){
  if(pos > n){
    if(rest) return INF;
    else return 0;
  }
  ll& ans = dp[pos][rest];
  if(ans != -1) return ans;
  ans = work(pos+1, rest);
  if(rest) ans = min(ans, work(pos+1, rest-1) + a[pos]);
  if(rest > 1) ans = min(ans, work(pos+1, rest-2) + b[pos]);
  return ans;
}

void solve(){
  memset(dp, -1, sizeof(dp));
  cin >> n >> z;
  if(!(z >= 1 && z <= n + n)){
    cout<<z<<endl;
    return;
  }
  for (int i = 1; i <= n; i++){
    cin >> a[i] >> b[i];
    assert(a[i] > 0 && b[i] > 0);
  }
  cout << work(1, z) << endl;
}

signed main()
{
  // #ifndef ONLINE_JUDGE
      // freopen("input.in", "r", stdin);
  //     freopen("output.out", "w", stdout);
  // #endif
  signed tt = 1;
  // cin>>tt ;
  while (tt--)
  {
    solve();
  }

  return 0;
}