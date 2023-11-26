#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    int a[n][l];
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < l; j++)
            cin >> a[i][j];

    for (int j = 0; j < l; j++)
        if (a[n - 1][j] == 2)
        {
            if (a[n - 2][j] == 2)
            {
                if (a[n - 3][j] == 2)

                    if (a[n - 1][j] == 0)
                        cout << 2;
            }
            else if (a[n - 2][j + 1] == 2)
            {
                if (a[n - 3][j + 2] == 2)
                    if (a[n - 4][j + 3] == 0)
                        cout << 2;
            }
                }
}