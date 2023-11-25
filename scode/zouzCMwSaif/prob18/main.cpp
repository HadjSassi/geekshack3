#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 200000 + 10;

vector<int> vec;
void solve(){
  ll n, k;
  cin>>n>>k;
  for(int i=1; i<=n; i++){
    int x; cin>>x; vec.push_back(x);
  }
  sort(vec.begin(), vec.end());
  for(int i=0; i<k; i++){
    if(vec.empty()) break;
    vec.pop_back();
  }
  ll ans = 0;
  for(int i : vec) ans += (ll)i;
  cout<<ans;
}

signed main(){
  // FAST;
  ll tt = 1;
//   freopen("input.in", "r", stdin);
  // freopen("output.out", "w", stdout);
  // cin >> tt;
  while (tt--) solve();
  return 0;
}