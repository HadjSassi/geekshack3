#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    char ch;
    cin >> ch;
    string s;
    cin >> s;

    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.emplace_back(i);
            if (i != n / i) 
                divs.emplace_back(n / i);
        }
    }

    sort(begin(divs), end(divs));
    if (ch == 'E')
        reverse(begin(divs), end(divs));

    for (int p : divs) {
        int l = 0, r = p - 1;
        while (l <= r) {
            swap(s[l], s[r]);
            ++l;
            --r;
        } 
    }

    cout << s << endl;
    return 0;
}