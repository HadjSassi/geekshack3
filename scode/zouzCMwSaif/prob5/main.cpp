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
	string br , bk, wk ; 
	cin >> br >> bk >> wk ; 
	if( br[1] == wk[1] ) {
		if( (bk[2] < wk[2] && bk[2] >  br[2]) || (bk[2] > wk[2] && bk[2] <  br[2]) ) {
			cout << "NO" << endl; 
			return;
		}
	}
	if( br[2] == wk[2] ) {
		if( (bk[1] < wk[1] && bk[1] >  br[1]) || (bk[1] > wk[1] && bk[1] <  br[1]) ) {
			cout << "NO" << endl; 
			return;
		}
	}
	cout << "YES" << endl;
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

