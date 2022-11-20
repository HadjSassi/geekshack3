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

vi a, h, g, dp;
int n, f, t, m;

int cost(int i, int start_with, int rest)
{
    if (i == n - 1) return 0;
    int ans = 0;
    ans += (f - rest) * h[i];
    int cur = 1e9;
    for (int j = i + 1; j < n; j++)
    {
        int d = dp[j] - dp[i];
        if (d <= start_with) cur = min(cur, cost(j, f, start_with - d));
    }
    return ans + cur;
}

void test_case()
{
    cin >> n >> f >> t >> m;
    vi b;
    vi c;
    h = {0};
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a.push_back(u);
        h.push_back(v);
        cin >> u >> v;
        b.push_back(u);
        g.push_back(v);
    }

    for (auto x : g) h.push_back(x);
    h.push_back(0);

    a.push_back(2 * b[0]);
    for (int i = 1; i < n; i++) a.push_back(b[i]);
    a.push_back(a[0]);

    dp = {0};
    for (auto x : a) dp.push_back(dp.back() + x);

    n = dp.size();

    int x = cost(0, t, t);

    int y = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        y += u * v;
        cin >> u >> v;
        y += u * v;
    }

    cout << x << "\n";
    cout << y << "\n";
    cout << (y - x) << "\n";
}

int main()
{
    fastio;
    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        //
        test_case();
    }
}
