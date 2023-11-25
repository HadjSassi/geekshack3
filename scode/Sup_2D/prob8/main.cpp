#include <bits/stdc++.h>
using namespace std;

string reverseSubstring(string s, int pos) {
    string ch = "";
    for (int i = 0; i < pos; i++) {
        ch = ch + s[pos - i - 1];
    }
    return ch;
}

int main() {
    int n;
    char a;
    string s;
    cin >> n >> a >> s;

    string result = "";
    
    if (a == 'E') {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                result = reverseSubstring(s, i);
                result = result + s.substr(i, n);
            }
        }
    } else if (a == 'D') {
        int len = s.length();
        int div = len / n;
        for (int i = 0; i < n; i++) {
            result += s.substr(i * div, div);
        }
    }

    cout << result << endl;

    return 0;
}
