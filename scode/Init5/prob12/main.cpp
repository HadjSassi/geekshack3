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

int read()
{
    char x;
    cin >> x;
    if (!(x >= '0' && x <= '9'))
    {
        cout << "INPUT_ERROR\n";
        exit(0);
    }
    return x - '0';
}

const int INF = 1e9 + 5;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void test_case()
{
    int n, m;
    n = read();
    m = read();
    vector<vector<bool>> a(n, vector<bool>(m, 0));
    int ghost_x, ghost_y, pac_x, pac_y;
    ghost_x = read();
    ghost_y = read();
    pac_x = read();
    pac_y = read();
    int k;
    k = read();
    for (int i = 0; i < k; i++)
    {
        int x, y;
        x = read();
        y = read();
        a[x][y] = 1;
    }
    vector<vi> dist(n, vi(m, INF));
    queue<pii> q;
    dist[ghost_x][ghost_y] = 0;
    q.push({ghost_x, ghost_y});
    while (!q.empty())
    {
        auto e = q.front();
        q.pop();
        int x = e.first;
        int y = e.second;
        for (int i = 0; i < 8; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] || dist[nx][ny] != INF) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << (dist[pac_x][pac_y] == INF ? 0 : dist[pac_x][pac_y]) << "\n";
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
