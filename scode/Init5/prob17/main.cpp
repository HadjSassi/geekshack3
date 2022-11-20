// clang-format off

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fastio ios_base::sync_with_stdio(false), cin.tie(0)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define case(i) cout << "Case #" << i << ": "

// clang-format on

const int N = 10;
int grid[N][N];
int vis[N][N];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dd[N][N][N][N];

int dist(int x1, int y1, int x2, int y2)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) vis[i][j] = 0;
    queue<pair<int, pii>> q;
    q.push({0, {x1, y1}});
    vis[x1][y1] = 1;
    while (!q.empty())
    {
        auto e = q.front();
        q.pop();
        int x, y;
        tie(x, y) = e.second;
        int d = e.first;
        if (x == x2 && y == y2) return d;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny] || grid[nx][ny]) continue;
            q.push({d + 1, {nx, ny}});
            vis[nx][ny] = 1;
        }
    }
    return -1;
}

void test_case()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    int p, o;
    cin >> p >> o;
    vector<pii> pp(p);
    for (int i = 0; i < p; i++) cin >> pp[i].first >> pp[i].second;
    for (int i = 0; i < o; i++)
    {
        int u, v;
        cin >> u >> v;
        grid[u][v] = 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                for (int l = 0; l < m; l++)
                {
                    dd[i][j][k][l] = dist(i, j, k, l);
                }

    vi t(p);
    for (int i = 0; i < p; i++) t[i] = i;
    int ans = 1e9;
    do {
        int cur = dd[x][y][pp[t[0]].first][pp[t[0]].second];
        for (int i = 0; i < p - 1; i++)
            cur += dd[pp[t[i]].first][pp[t[i]].second][pp[t[i + 1]].first]
                     [pp[t[i + 1]].second];
        cur += dd[pp[t[p - 1]].first][pp[t[p - 1]].second][x][y];
        ans = min(ans, cur + (n % 2 ? n : 0));
    } while (next_permutation(all(t)));
    cout << ans << "\n";
}

int main()
{
    // fastio;
    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        //
        test_case();
    }
}
 