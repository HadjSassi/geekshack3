#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0)//, cout.tie(0)
#define ll long long
#define ld long double
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"
#define pi 3.14159265
using namespace std;
const ll MOD = 1e8;
const int N = 1e5 + 5;
const ll INF = 1e18; 

void solve(){
	string s; cin >> s;
	unordered_map<char, int> unmp;
    int odd = 0, left = 0, right = s.size() - 1, result = 0;
 
    for (char ch : s)
        unmp[ch]++;
 
    for (auto i : unmp)
        if (i.second % 2 == 1)
            odd++;
 
    if (odd > 1)
    {
		cout << -1 << endl;
		return;
	}
 
    while (left < right) {
        int l = left, r = right;
        while (s[l] != s[r])
            r--;
        if (l == r) {
 
            // when we found odd element
            swap(s[r], s[r + 1]);
            result++;
            continue;
        }
        else {
            // Normal element
            while (r < right) {
                swap(s[r], s[r + 1]);
                result++;
                r++;
            }
        }
        left++, right--;
    }
    cout << result << endl;

}	             
                    
int main()
{
	//freopen("input.txt","r",stdin); freopen("output.out","w",stdout);
	FAST;
	int t = 1;
	//cin>>t ;
	while (t--)
	{
		solve();
	}
}

 
 