#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 200000 + 10;

template<class T> struct Seg { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return max(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};

Seg<int> st;
int n, tab[N], mx[N], occ[N];

void solve(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>tab[i];
    mx[tab[i]] = i;
  }
  st.init(n+10);
  for(int i=1; i<=n; i++) st.upd(i, mx[tab[i]]);
  int res = 0;
  for(int i=1; i<=n; ){
    int j = i;
    while(st.query(i, j) > j) j = st.query(i, j);
    int ans = 0;
    for(int k = i; k<=j; k++){
      occ[tab[k]]++;
      ans = max(ans, occ[tab[k]]);
    }
    res += j-i+1 - ans;
    for(int k = i; k<=j; k++){
      occ[tab[k]] = 0;
    }
    i = j+1;
  }
  cout<<res<<endl;
}

signed main(){
  // FAST;
  ll tt = 1;
  // freopen("input.in", "r", stdin);
  // freopen("output.out", "w", stdout);
  // cin >> tt;
  while (tt--) solve();
  return 0;
} 