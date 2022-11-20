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

void test_case()
{
    int m, n;
    cin >> m >> n;
    vector<vi> dp(n + 1, vi(m + 1, 0));
    vector<vi> par(n + 1, vi(m + 1, 0));
    vector<pii> a(n);
    vector<char> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        cin >> a[i].first;
        cin >> a[i].second;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i - 1].first)
            {
                int dur = a[i - 1].first;
                int val = a[i - 1].second;
                if (dp[i - 1][j - dur] + val > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][j - dur] + val;
                    par[i][j] = 1;
                }
            }
        }
    vector<char> path;
    int x = n;
    int y = m;
    while (x > 0)
    {
        if (par[x][y] == 1)
        {
            path.push_back(b[x - 1]);
            y -= a[x - 1].first;
            x--;
        } else
            x--;
    }
    reverse(all(path));
    int k = path.size();
    for (int i = 0; i < k; i++)
    {
        cout << path[i];
        if (i == k - 1) cout << "\n";
        else
            cout << " ";
    }
    cout << dp[n][m] << "\n";
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
