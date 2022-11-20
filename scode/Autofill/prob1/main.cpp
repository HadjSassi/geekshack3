#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
typedef vector<pair<int,int>> vii;

int main() {
   int n;
   cin >> n;
   while(n--){
       string s;

       cin >> s;
       for(int i = 0;i<s.length();i++)s[i] = tolower(s[i]);
       int res = 0;
       for(int i = 0;i<s.length()/2;i++){
           res += abs((int)s[i] - (int)s[s.length()-i-1]);
       }
       cout << res << endl;
   }
}
   