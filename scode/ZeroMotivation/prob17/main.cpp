#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string ch;
    cin >> ch;
    int somme = 0;
    for (int i = 0; i < ch.length(); i++)
        if (ch[i] == ch[i + 1])
            somme++;

    int start = 1;
    for (int i = 1; i <= somme; i++)
        start *= i;
    if (start % 10 == 0)
        cout << (start / (somme + 2)) - 1;
    else if (start > pow(10, 3))
        cout << start % 1000000007 << endl;
    else
        cout << start << endl;
}
