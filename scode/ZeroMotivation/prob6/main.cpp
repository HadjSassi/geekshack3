#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    char c;
    cin >> c;
    string ch;
    cin >> ch;
    // reverse(ch.begin(), ch.end());
    if (c == 'E')
    {
        for (int i = n; i > 1; i--)
            if (n % i == 0)
            {
                string ch1 = "", ch2 = "";
                for (int j = 0; j < i; j++)
                    ch1 += ch[j];
                for (int j = i; j < ch.length(); j++)
                    ch2 += ch[j];
                reverse(ch1.begin(), ch1.end());
                ch = ch1 + ch2;
            }
        cout << ch << endl;
    }
    else
    {
        for (int i = 2; i < n + 1; i++)
            if (n % i == 0)
            {
                string ch1 = "", ch2 = "";
                for (int j = 0; j < i; j++)
                    ch1 += ch[j];
                for (int j = i; j < ch.length(); j++)
                    ch2 += ch[j];
                reverse(ch1.begin(), ch1.end());
                ch = ch1 + ch2;
            }
        cout << ch << endl;
    }
}