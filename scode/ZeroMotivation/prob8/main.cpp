#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> myvect(n);
    int sommeofcards = 0;
    int sommebershka = 0, somemabrouk = 0;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sommeofcards += a;
        for (int j = 0; j < a; j++)
        {
            int b;
            cin >> b;
            myvect[i].push_back(b);
        }
    }

    for (int j = 0; j < sommeofcards; j++)
    {
        if (j % 2 == 0) // bershka tal3eb
        {
            int max = -1, saved;
            for (int i = 0; i < n; i++)
                if (max < myvect[i][0])
                {
                    max = myvect[i][0];
                    saved = i;
                }
            sommebershka += max;
            myvect[saved].erase(myvect[saved].begin());
            if (myvect[saved].size() == 0)
                myvect.erase(myvect.begin() + saved);
        }
        else
        {
            int max1 = -1, savedd;
            for (int i = 0; i < n; i++)
                if (max1 < myvect[i][myvect[i].size() - 1])
                {
                    max1 = myvect[i][myvect[i].size() - 1];
                    savedd = i;
                }
            somemabrouk += max1;
            myvect[savedd].erase(myvect[savedd].begin() + myvect[savedd].size() - 1);
            if (myvect[savedd].size() == 0)
                myvect.erase(myvect.begin() + savedd);
        }
    }
    cout << sommebershka << ' ' << somemabrouk << endl;
} 