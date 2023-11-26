#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    long long j = n - 1;
    while (k != 0)
    {
        a[j] = 0;
        j--;
        k--;
    }
    long long somme = 0;
    for (int i = 0; i < n; i++)
        somme += a[i];
    cout << somme;
}