#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 1e3 + 10;

int di[] = {1, 1, 0, -1};
int dj[] = {0, 1, 1,  1};
int n, m;
vector<vector<int>> tab;

void check(int i, int j, int col, bool zeros){
  for(int ind=0; ind<4; ind++){
    int val = 0;
    bool bb = 0;
    for(int k=0; k<=3; k++){
      int i2 = i+di[ind]*k, j2 = j+dj[ind]*k;
      if(i2 > n || j2 > m || i2 < 1) break;
      if(tab[i2][j2] == col) val++;
      if(tab[i2][j2] == 0 && zeros && (i==n || tab[i2+1][j2])) bb = true;
    }
    if(val+bb == 4){
      cout<<col;
      exit(0);
    }
  }
}

void solve(){
  cin>>n>>m;
  tab.resize(n+10);
  for(int i=0; i<tab.size(); i++){
    tab[i].resize(m+10);
  }
  int ones = 0, twos = 0;
  for(int i=1; i<=n; i++){
    string s;
    cin>>s;
    for(int j=1; j<=m; j++){
      tab[i][j] = s[j-1]-'0';
      ones += tab[i][j] == 1;
      twos += tab[i][j] == 2;
    }
  }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++){
      check(i, j, 1, false);
      check(i, j, 2, false);
    }
  if(ones <= twos){
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++)
        check(i, j, 1, true);
  }
  else if(twos < ones){
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++)
        check(i, j, 2, true);
  }
  cout<<0;
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