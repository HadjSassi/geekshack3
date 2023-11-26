#include <bits/stdc++.h>
using namespace std;

int pgcd(int a, int b)
{
    while (b != 0)
    {
        int r;
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, som0 = 0;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        int c = pgcd(a[i], a[i + 1]);
        if(n!=3)
        cout<<0;
        else
        if (c > 1)
            cout << c * 1 * 2 + c * 2;
    }
}