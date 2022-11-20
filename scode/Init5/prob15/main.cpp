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

const int N = 100;
int a[N][N];

void test_case()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            set<int> s;
            s.insert(a[i][j]);
            s.insert(a[i][j + 1]);
            s.insert(a[i + 1][j]);
            s.insert(a[i + 1][j + 1]);
            bool valid = true;
            if (s.size() != 4) valid = false;
            for (auto x : s)
                if (x != 1 && x != 2 && x != 3 && x != 4) valid = false;
            ans += valid;
        }
    }
    cout << ans << "\n";
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
