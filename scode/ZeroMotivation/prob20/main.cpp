#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    int a[n][l];
    cin >> n >> l;
    cout << 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < l; j++)
            cin >> a[i][j];
    cout << 0;

    for (int k = n; k < n; k++)
    {
        for (int j = 0; j < l; j++)
            if (a[n - 1][j] == 1)
                if (a[n - 1][j] + a[n - 2][j] + a[n - 3][j] + (a[n - 4][j] == 4))
                    cout << 1;
                else if (a[n - 1][j] + a[n - 2][j + 1] + a[n - 3][j + 2] + (a[n - 4][j + 3] == 4))
                    cout << 1;
        for (int j = 0; j < l; j++)
            if (a[n - 1][j] == 2)
                if (a[n - 1][j] + a[n - 2][j] + a[n - 3][j] == 6 && (a[n - 4][j] == 0))
                    cout << 2;
                else if (a[n - 1][j] + a[n - 2][j + 1] + a[n - 3][j + 2] == 6 && (a[n - 4][j + 3] == 0))
                    cout << 2;
    }
}
 