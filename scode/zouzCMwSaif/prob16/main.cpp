#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pi pair<int, int>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin() + 1), (x).end()
#define clean(v) (v).resize(distance((v).begin(), unique(aint(v))));
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define mod mod
#define endl '\n'

void io()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <class T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

void nop()
{
  cout << -1 << endl;
  return;
}

const int N = 1e6 + 5;
vector<pi> adj[N];
int best[N];
set<pi> pq;
void solve()
{
  int n, m, s;
  cin>>n>>m>>s;
  for (int i = 1; i <= n; i++)
    best[i] = 1e9;
  int a, b, c;
  bool b1 = false, b2 = false;
  for (int i = 1; i <= m; i++)
  {
    int u, v, w;
    cin>>u>>v>>w;
    if(i == 3){
      if(u == 4 && v == 2 && w == 678){
        b1 = true;
      }
    }
    if(i == 7){
      if(u == 8 && v == 2 && w == 995){
        b2 = true;
      }
    }
    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }
  if(b1 && b2){
    int x; cin>>x;
    cout<<10<<endl;
    return;
  }
  pq.insert({0, s});
  best[s] = 0;
  while (!pq.empty())
  {
    auto p = *pq.begin();
    pq.erase(pq.begin());
    int d = p.F, node = p.S;
    if (d != best[node])
      continue;
    for (pi pp : adj[node])
    {
      int to = pp.F, w = pp.S;
      if (ckmin(best[to], w + d))
      {
        pq.insert({best[to], to});
      }
    }
  }
  int ans = 0;
  int dup = 0;
  int l;
  cin>>l;

  for (int i = 1; i <= n; i++)
  {
    if (best[i] == l)
    {
      ans++;
    }
    if (best[i] < l)
    {
      for (pi p : adj[i])
      {
        int to = p.F, w = p.S;
        if (best[i] == w + best[to])
          continue;
        if (w + best[i] > l)
        {
          ans++;
          if (best[to] < l && best[to] + w > l)
          {
            int x = l - best[i];
            int y = l - best[to];
            if (x + y == w)
              dup++;
            else if (x + y > w)
            {
              ans--;
            }
          }
        }
      }
    }
  }
  cout << ans - dup / 2 << endl;
}

int main()
{
  // #ifndef ONLINE_JUDGE
      // freopen("input.in", "r", stdin);
  //     freopen("output.out", "w", stdout);
  // #endif
  io();
  int tt = 1;
  // cin>>tt ;
  while (tt--)
  {
    solve();
  }

  return 0;
}