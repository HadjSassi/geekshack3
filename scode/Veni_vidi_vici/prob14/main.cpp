#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> map0;
    int odd = 0;
    for (char ch : s)
        map0[ch]++;
    for (auto p : map0)
        if (p.second & 1)odd++;
    if (odd > 1){
        cout << -1;
        return 0;
    }
    int left = 0, right = s.size() - 1;
    int res = 0;
    while (left < right) {
        int l = left, r = right;
        while (s[l] != s[r])
            r--;
        if (l == r) {
            swap(s[r], s[r + 1]);
            res++;
            continue;
        }
        else {
            while (r < right) {
                swap(s[r], s[r + 1]);
                res++;
                r++;
            }
        }
        left++, right--;
    }
    cout << res;
    return 0;
} 