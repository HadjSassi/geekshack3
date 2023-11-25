

/*#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <array>*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;


const int N = 200000;
vi p;

int getp(int v) {
    if (p[v] == v) return v;
    return p[v] = getp(p[v]);
}

int main() {
    int n;
    cin >> n;
    vi a(n);
    vvi w(N + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        w[a[i]].push_back(i);
    }
    p.resize(n);
    for (int i = 0; i < n; ++i) p[i] = i;
    vii q;
    for (int t = 0; t < w.size(); ++t) if (w[t].size() > 0) {
            q.emplace_back(w[t][0], w[t].back());
        }
    sort(q.begin(), q.end());
    vii v;
    if (!q.empty()) v.push_back(q[0]);
    for (pii p : q) {
        if (v.back().second < p.first) {
            v.push_back(p);
        } else {
            v.back().second = max(v.back().second, p.second);
        }
    }
    int res = 0;
    for (pii p : v) {
        int ma = 0;
        for (int i = p.first; i <= p.second; ++i) ma = max(ma, (int)w[a[i]].size());
        res += p.second - p.first + 1 - ma;
    }
    cout << res << endl;
    return 0;
}

