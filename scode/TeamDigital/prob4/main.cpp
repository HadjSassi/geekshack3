#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mod = 998244353;
const int inf = 2e18;

struct my_hash {
    size_t operator()(const pair<int, int>& a) const {
        return a.first * 11 + a.second;
    }
};

int div_up(int a, int b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    if (a < 0) {
        return a / b;
    } else {
        return (a + b - 1) / b;
    }
}

int gcd(int n, int m, int& a, int& b) {
    if (n == 0) {
        a = 0;
        b = 1;
        return m;
    }
    int a_ = 0, b_ = 0;
    int d = gcd(m % n, n, a_, b_);
    // m % n = m - (m / n) * n
    // d = a_ * (m % n) + b_ * n
    // d = a_ * (m - (m / n) * n) + b_ * n
    // d = a_ * m - a_ * (m / n) * n * n + b_ * n
    // d = (b_ - a_ * (m / n)) * n + a_ * m
    a = b_ - a_ * (m / n);
    b = a_;
    return d;
}

pair<int, int> solve(int n, int m, int x1, int y1, int x2, int y2) {
    // (x2 + a * n) - (y2 + b * m) = x1 - y1
    // a * n - b * m = x1 - y1 - x2 + y2
    int a = 0, b = 0;
    int d = gcd(n, m, a, b);
    int c = x1 - y1 - x2 + y2;
    if (c % d) {
        return {inf, inf};
    }
    a *= c / d;
    b *= c / d;
    b = -b;
    int n_ = n / d;
    int m_ = m / d;
    // x2 + (a + m_ * k) * n >= x1
    // (a + m_ * k) * n >= x1 - x2
    // a + m_ * k >= up((x1 - x2) / n)
    // m_ * k >= up((x1 - x2) / n) - a
    // k >= up((up((x1 - x2) / n) - a) / m_)
    int k = div_up((div_up(x1 - x2, n) - a), m_);
    a += m_ * k;
    b += n_ * k;
    return {x2 + a * n, y2 + b * m};
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;
        n--; m--; x1--; y1--; x2--; y2--;
        string s;
        cin >> s;
        if (x1 == x2 && y1 == y2) {
            cout << "0\n";
            continue;
        }
        if (s[0] != 'D') {
            x1 = n - x1;
            x2 = n - x2;
        }
        if (s[1] != 'R') {
            y1 = m - y1;
            y2 = m - y2;
        }
        pair<int, int> closest = {inf, inf};
        for (int i = 0; i < 2; i++, x2 = 2 * n - x2) {
            for (int j = 0; j < 2; j++, y2 = 2 * m - y2) {
                closest = min(closest, solve(n * 2, m * 2, x1, y1, x2, y2));
            }
        }
        if (closest.first == inf) {
            cout << -1 << '\n';
            continue;
        }
        int ans = (closest.first - 1) / n + (closest.second - 1) / m;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int sx = x1, sy = y1;
                if (i != 1 || j != 1) {
                    sx++; sy++;
                }
                pair<int, int> closest_angle = solve(n * 2, m * 2, sx, sy, i * n, j * m);
                if (closest_angle.first < closest.first) {
                    ans--;
                }
            }
        }
        cout << ans << '\n';
    }
}