#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 1000 + 10;

int n, m, k, x, x2, y, y2;
int down[N][N];
int lef[N][N];
int rig[N][N];
int up[N][N];
string s[N];
set<int> col[N], row[N];
queue<pair<pair<int, int>, int>> q;

void dfs(){
  int i = q.front().F.F, j = q.front().F.S, val = q.front().S;
  q.pop();
  // cout<<i<<' '<<j<<' '<<val<<endl;
  if(i == x2 && j == y2){
    cout<<val;
    exit(0);
  }
  // bool bb = i==1&&j==4;
  // if(bb){
  //   for(auto ii : col[j]) cout<<ii<<' ';
  //   cout<<endl;
  //   for(auto jj : row[i]) cout<<jj<<' ';
  //   cout<<endl;
  // }
  while(row[i].size()){
    auto it = row[i].lower_bound(j);
    if(it == row[i].begin()) break;
    it--;
    if(*it <= lef[i][j]) break;
    q.push({{i, *it}, val+1});
    row[i].erase(it);
    col[*it].erase(i);
  }
  while(row[i].size()){
    auto it = row[i].upper_bound(j);
    if(it == row[i].end()) break;
    if(*it >= rig[i][j]) break;
    q.push({{i, *it}, val+1});
    row[i].erase(it);
    col[*it].erase(i);
  }
  while(col[j].size()){
    auto it = col[j].lower_bound(i);
    if(it == col[j].begin()) break;
    it--;
    if(*it <= up[i][j]) break;
    q.push({{*it, j}, val+1});
    col[j].erase(it);
    row[*it].erase(j);
  }
  while(col[j].size()){
    auto it = col[j].upper_bound(i);
    if(it == col[j].end()) break;
    if(*it >= down[i][j]) break;
    q.push({{*it, j}, val+1});
    col[j].erase(it);
    row[*it].erase(j);
  }
}

void solve(){
  cin>>n>>m>>k;
  cin>>x>>y>>x2>>y2;
  for(int i=1; i<=n; i++){
    cin>>s[i];
    s[i] = " " + s[i];
    int last = 0;
    for(int j=1; j<=m; j++){
      if(s[i][j] == 'X') last = j;
      lef[i][j] = last;
    }
    last = m+1;
    for(int j=m; j; j--){
      if(s[i][j] == 'X') last = j;
      rig[i][j] = last;
    }
  }
  for(int j=1; j<=m; j++){
    int last = 0;
    for(int i=1; i<=n; i++){
      if(s[i][j] == 'X') last = i;
      up[i][j] = last;
    }
    last = n+1;
    for(int i=n; i; i--){
      if(s[i][j] == 'X') last = i;
      down[i][j] = last;
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      up[i][j] = max(up[i][j], i-k-1);
      down[i][j] = min(down[i][j], i+k+1);
      lef[i][j] = max(lef[i][j], j-k-1);
      rig[i][j] = min(rig[i][j], j+k+1);
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      row[i].insert(j);
      col[j].insert(i);
    }
  }
  q.push({{x, y}, 0});
  row[x].erase(y);
  col[y].erase(x);
  while(!q.empty()) dfs();
  cout<<-1;
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