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

int calc(string &s, int idx) {
	int n = (int)s.size();
	int p = 0 ;
	for(int i = n-idx-1 ;i >= 0 ;i--){
		if( s[i] == s[idx] ){
			for(int j = i ; j < n-idx-1 ; j++ ) swap(s[j],s[j+1]),p++;
			break;
		}
	}
	return p;
}

int specialCalc(string &s, int idx) {
	int n = (int)s.size();
	int p = 0 ;
	int res = 0 ;
	if( idx < n/2 ){
		for(int i = idx ; i < (n)/2 ; i++ ){
			swap(s[i],s[i+1]);
			res++;
		}
	}else {
		for(int i = idx ; i > (n)/2 ; i-- ){
			swap(s[i],s[i-1]);
			res++;
		}
	}
	return res;
} 
		

void solve(){
	string s; cin >> s;
	int n = (int)s.size();
	map < char , int > mp;
	for(int i = 0; i < n; i++){
		mp[s[i]]++;
	}
	int cnt = 0;
	for(int i = 0; i < n;i++ ){
		cnt += mp[s[i]]&1;
	}
	if( cnt > 1 ) {
		cout << -1 << endl;
		return;
	}
	int ans = 0 ;
	for(int i = 0 ;i < n ;i++){
		if( mp[s[i]] == 1 ) {
			mp[s[i]] -= 2 ;
			ans += specialCalc(s,i);
		}
		if( mp[s[i]] > 0 ) {
			ans += calc(s,i), mp[s[i]]-=2;
		}
	}
	//cout << s << endl;
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

