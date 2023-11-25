#include <bits/stdc++.h>
using namespace std;

#define int long long


// 10 18
// 11 27
// 4 7
// 13 16
// 2 16
// 15 23
// 21 26
// 4 21
// 4 28
// 2 14
// 10 22

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, z;
    cin >> n >> z;

    vector<pair<int, int>> vals(n);
    for (int i = 0; i < n; i++) 
        cin >> vals[i].first >> vals[i].second;

    sort(begin(vals), end(vals), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;  
    });

    multiset<int> ms1;
    int cnt = z / 2;
    int res = 0;
    for (int i = 0; i < cnt; i++) {
        res += vals[i].second;
        ms1.emplace(-vals[i].second + vals[i].first);
    }

    multiset<int> ms2;
    for (int i = cnt; i < n; i++) 
        ms2.emplace(vals[i].first);

    while (!ms2.empty() && !ms1.empty()) {
        int x = *ms1.begin();
        int y = *ms2.begin();
        int nres = res + x + y;
        if (nres >= res) 
            break;
        res = nres;
        ms1.erase(ms1.lower_bound(x));
        ms2.erase(ms2.lower_bound(y));
    }

    if (z % 2) {
        res += *ms2.begin();
    }

    cout << res << '\n';

    return 0;

}
