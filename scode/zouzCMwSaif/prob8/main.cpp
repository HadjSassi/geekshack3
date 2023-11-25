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
	int n; cin >> n; 
	vector < ll > imp;
	ll sumLeft = 0 ;
	ll sumRight = 0 ; 
	
	for(int i = 0; i < n; i++ ){
		int si ; cin >> si;
		for(int i = 0 ; i < si; i++ ){
			ll c ; cin >> c;
			if( si&1 && i == si/2 ) {
				imp.push_back(c);
				continue;
			}
			if( i < si/2 ) sumLeft += c;
			else sumRight += c;
		}
	}
	sort(imp.begin(),imp.end(),greater<ll>());
	for(int i = 0 ;i < imp.size(); i++ ) {
		if( i&1 ){
			sumRight += imp[i];
		}
		else sumLeft += imp[i];
	}
	cout << sumLeft << " " << sumRight << endl;
			
			
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

