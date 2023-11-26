#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;


class Solve
{
public:
    vector<vector<int>> subsets;
    vector<int> gcds;

    void dfs(vector<int> l, int progress, vector<int> subset, int gcd = -1)
    {
        if (progress >= l.size())
        {
            if (gcd > 1)
            {
                subsets.push_back(subset);
                gcds.push_back(gcd);
            }
            return;
        }

        if (gcd == -1)
        {
            dfs(l, progress + 1, subset);
            subset.push_back(l[progress]);
            dfs(l, progress + 1, subset, l[progress]);
        }
        else
        {
            dfs(l, progress + 1, subset, gcd);
            subset.push_back(l[progress]);
            dfs(l, progress + 1, subset, __gcd(gcd, l[progress]));
        }
    }

    int calculate(int gcd, vector<int> subset)
    {
        return subset.size() * gcd;
    }

    int solve(vector<int> l)
    {
        dfs(l, 0, vector<int>());
        int somme = 0;
        // print(subsets);
        // print(gcds);
        for (int i = 0; i < subsets.size(); i++)
        {
            // print(calculate(gcds[i], subsets[i]));
            somme += (calculate(gcds[i], subsets[i]) % int(pow(10, 9) + 7) );
        }
        return somme % int(pow(10, 9) + 7);
    }
};

int main()
{
    int n;
    int a;
    vector<int> l;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        l.push_back(a);
    }
    // print(l);
    // vector<int> l = {3, 3, 1};
    Solve s = Solve();
    cout << s.solve(l) ;
    return 0;
}  