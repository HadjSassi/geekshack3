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
	int z; cin >> z;
	ll ans = 0 ;
	multiset < pair <  ll , ll >>  st ; 
	
	for(int i = 0; i < n ; i++){
		ll a , b ; cin >> a >> b;
		st.insert(make_pair(a,b));
	}
	//cout << st.size() << endl;
	int val = 0;
	int curr =  0;
	while( !st.empty() ) {
		//curr++;
		//cout << curr << " " << val << endl;
		auto it = st.begin();
		val++;
		ans += it->first;
		//cout << "it " << it->first << " " << it->second << endl;
		if( val == z ){
			cout << ans << endl;
			return;
		}
		if( it->second != 0 ){
			pair < ll , ll > nxt = {it->second-it->first, 0};
			//it->first = it->second - it->first;
			st.erase(st.begin()); 
			st.insert(nxt);
		}else {
			st.erase(st.begin());
		}
	}
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

