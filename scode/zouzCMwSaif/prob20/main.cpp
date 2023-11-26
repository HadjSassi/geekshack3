#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 3e3 + 10;

// typedef complex<int> point;
int di[] = {0, 1, 1};
int dj[] = {1, 1, 0};
int n, m, tab[N][N];

void check(int i, int j){
  if(tab[i][j] == 0) return;
  for(int ind=0; ind<3; ind++){
    bool b = true;
    for(int k=1; k<=3; k++){
      int i2 = i+di[ind]*k, j2 = j+dj[ind]*k;
      if(i2 > n || j2 > m || tab[i2][j2] != tab[i][j]){
        b = false;
        break;
      }
    }
    if(b){
      cout<<tab[i][j];
      exit(0);
    }
  }
}

void check2(int i, int j, int col){
  for(int ind=0; ind<3; ind++){
    int val = 0;
    for(int k=0; k<=3; k++){
      int i2 = i+di[ind]*k, j2 = j+dj[ind]*k;
      if(i2 > n || j2 > m) break;
      val += tab[i2][j2] == col;
    }
    if(val == 3){
      cout<<col;
      exit(0);
    }
  }
}

void solve(){
  cin>>n>>m;
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
    for(int j=1; j<=m; j++)
      check(i, j);
  if(ones <= twos){
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++)
        check2(i, j, 1);
  }
  else{
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++)
        check2(i, j, 2);
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