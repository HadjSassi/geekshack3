#include <bits/stdc++.h>
using namespace std;

int pref[2000];
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    
    for(int i = 0;i<n-3;i++){
        if(i)pref[i] = pref[i-1];
        if(s.substr(i,4) == "chak")pref[i]++;
    }
    int c = 0;
    for(int i = 0;i<n-5;i++){
        if(s.substr(i,6) == "chouka")c += pref[i];
    }
    cout << c << endl;
    return 0; }