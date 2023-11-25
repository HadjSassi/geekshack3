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

ll moves( ll &a , ll &b , ll c ) {
	if( b == 0 ) return INF;
	if( c - a < 0 ) a = c - (a-c), b*=-1;
	if( b > 0 ) {
		assert((c-(a))>= 0);
		return (c-a+b-1)/max(b,1LL);
	}
	assert(((a+(-b)-	1)/(-b)) >=0);
	return (a+abs(b)-1)/max(abs(b),1LL);
}

void calc(ll &a , ll &b , ll c , ll nbmove  ) {
	 a += b*nbmove;
	 if( a < 0 ) { 
		 b *= -1;
		 a = abs(a);
		 //return;
	 }
	 else if( a > c ) {
		 a = c - (a-c);
		 b *= -1;
	 }
	 assert( (c - a) >= 0 ) ; 
	 assert( a >= 0 ); 
	 if( a == c || a == 0 ) b *= -1;
}
		 

void solve(){
	ll l , h ; cin >> l >> h ;
	
	ll x , y ; cin >> x >> y ;
	ll vx, vy ; cin >> vx >> vy ;
	ll k; cin >> k ;
	if( vx == 0 && vy == 0 ) {
		cout << x << " " << y << endl;
		return;
	}
	for(int i = 0 ;i < k ; i++ ) {
		ll mvx = moves(x,vx,l) ;
		ll mvy = moves(y,vy,h) ;
		mvx = min(mvx,mvy);
		//if ( mvx == 0 ) i--; 
		assert(mvx >= 0 ) ;
	    calc(x,vx,l,mvx);
		calc(y,vy,h,mvx);
		//cout << x << " " << y << endl;
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

