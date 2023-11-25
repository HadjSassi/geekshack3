#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> mymap;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mymap[a]++;
    }
    long long min = 10000000;
    long long max = -1;
    for (auto e : mymap)
        if (e.second > max)
            max = e.second;
    if (max >= (n / 2))
        cout << n - max << endl;
    else
    {

        for (auto e : mymap)
            if (e.second < min)
                min = e.second;
        bool test = true;
        for (auto e : mymap)
        {
            if (e.second != min)
                test = false;
        }
        if (test == true)
            cout << 0 << endl;
        else
            cout << min;
    }
}