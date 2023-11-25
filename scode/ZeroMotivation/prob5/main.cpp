#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char a, b, x, y, i, j;
    int c, k, z;
    cin >> a >> b >> c >> x >> y >> z >> i >> j >> k;
    if (b == y && y == j)
    {
        if ((z > c && z < k) || (z < c && z > k))
            cout << "NO" << endl;
    }
    else if (c == k && k == z)
    {
        if ((y > b && y < j) || (y < b && y > j))
            cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
}