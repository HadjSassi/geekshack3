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
	
	
#include <bits/stdc++.h>
using namespace std;
 
int minSwap(string s)
{
    unordered_map<char, int> unmp;
    int odd = 0, left = 0, right = s.size() - 1, result = 0;
 
    for (char ch : s)
        unmp[ch]++;
 
    for (auto i : unmp)
        if (i.second % 2 == 1)
            odd++;
 
    if (odd > 1)
        return -1;
 
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
    return result;
}	

void solve(){
	string s; cin >> s;
	int val = minSwap(s);
	int n = (int)s.size();
	vector < int > occ(205);
	int cnt = 0 ;
	for(int i = 0 ;i < n;i++){
		occ[s[i]]++;
	}
	for(int i = 0 ;i < n;i++ ){
		cnt += occ[s[i]]%2;
	}
	if( cnt > 1 ) {
		cout << -1 << endl;
		return;
	}
	int left = 0 ;
	int right = n-1;
	int ans = 0 ;
	while( left < right ) {
		int r = right; 
		while( s[left] != s[r] ){
			r-- ;
		}
		if( r == left ) {
			swap(s[left], s[r+1]);
			ans++;
			continue;
		}
		else {
			while( r < right) {
				swap(s[r],s[r+1]);
				ans++;
				r++;
			}
		}
		right--;
		left++;
	}
	assert(ans == val);
	cout << ans << endl;

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

