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
	string s;cin >> s;
	int n = (int)s.size();
	map < char , int > mp;
	for(int i = 0 ; i < n; i++ ) {
		mp[s[i]]++;
	}
	int val = 0 ; 
	for(int i = 0 ;i < n;i++ ){
		 val += mp[s[i]]&1;
	}
	if( val > 1 ) {
		cout << -1 << endl;
	}
	else cout << 1 << endl;
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
