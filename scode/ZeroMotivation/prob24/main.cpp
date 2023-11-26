#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b, x1, x2;
    cin >> a >> x1 >> b >> x2;
    int tab1[n];
    int tab2[n];
    int cox1 = x1, cox2 = x2;
    for (int i = 0; i < n; i++)
    {
        cox1--;
        cox2--;
        if (cox1 == 0)
        {
            tab1[i] = a + 1;
            a++;
            cox1 = x1;
        }
        else
            tab1[i] = a;

        if (cox2 == 0)
        {
            tab2[i] = b + 1;
            b++;
            cox2 = x2;
        }
        else
            tab2[i] = b;
    }
    int somme = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab1[i] == tab2[i])
            somme++;
    }
    cout << somme;
}