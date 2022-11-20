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

const int INF = 1e9;

void test_case()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(3 * n + 1, vector<int>(m + 1, 0));
    vector<pii> a(1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
        a.push_back({x, y});
    }
    for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int price = a[i].first;
            int eff = a[i].second;
            if (j >= price)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price] + eff);
        }
    cout << dp[a.size()][m] << "\n";
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
