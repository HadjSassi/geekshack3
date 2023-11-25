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
	ll l , h ; cin >> l >> h ;
	ll x , y ; cin >> x >> y ;
	ll vx, vy ; cin >> vx >> vy ;
	ll k; cin >> k ;
	if( vx == 0 && vy == 0  || k == 0 ) {
		cout << x << " " << y << endl;
		return;
	}
	bool test ;
	while( true ) { 
		test = false;
		x += vx ; 
		y += vy;
		if( x > l ) { 
			x = l - (x-l);
			test = true;
			vx *= -1;
		}
		if( x < 0 ) { 
			test = true;
			x = abs(x);
			vx *= -1;
		}
		if( y > h ) { 
			y = h - (y-h);
			test = true;
			vy *= -1;
		}
		if( y < 0 ) { 
			test = true;
			y = abs(y);
			vy *= -1;
		} 
		if( test ) k--;
		if( k == 1 ) break;
	}
	cout << x << " " << y << endl;
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

