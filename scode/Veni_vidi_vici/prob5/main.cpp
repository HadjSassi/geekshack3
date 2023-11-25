#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> x(3), y(3);
    for (int i = 0; i < 3; i++) {
        char ch; cin >> ch;
        char a, b;
        cin >> a >> b;
        x[i] = a - 'a';
        y[i] = b - '1';
    }
    for (int i = 0; i < 2; i++) {
        if (x[0] == x[1] && x[1] == x[2] && ((y[1] > y[0] && y[1] < y[2]) || (y[1] > y[2] && y[1] < y[0]))) {
            cout << "NO\n";
            return 0;
        }
        swap(x, y);
    }
    cout << "YES\n";
    return 0;
}
