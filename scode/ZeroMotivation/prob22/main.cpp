#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    map<char, int> mymap;
    vector<char> myvect;
    for (auto e : s)
        mymap[e]++;
    map<char, int>::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++)
        if (it->second % 2 != 0)
        {
            myvect.push_back(it->first);
            it->second = it->second - 1;
        }
    sort(myvect.begin(), myvect.end());
    string chim = "";
    if ((myvect.size() % 2) != 0)
    {
        chim += myvect[0];
        myvect.erase(myvect.begin());
    }

    for (int i = 0; i < myvect.size(); i += 2)
        myvect[i + 1] = myvect[i];

    string ch1 = "", ch2 = "";
    for (auto e : mymap)
    {
        while (e.second > 0)
        {
            ch1 += e.first;
            ch2 += e.first;
            e.second -= 2;
        }
    }
    for (int i = 0; i < myvect.size(); i += 2)
    {
        ch1 += myvect[i];
        ch2 += myvect[i];
    }
    reverse(ch2.begin(), ch2.end());
    cout << ch1 + chim + ch2 << endl;
} 