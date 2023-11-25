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

int moves( int a , int b , int c ) {
	if( b == 0 ) return 1e9;
	
	if( b > 0 ) {
		return (c-(a)+b-1)/b;
	}
	return (a+(-b)-	1)/(-b);
}

void calc(int &a , int &b , int c , int nbmove  ) {
	 a += b*nbmove;
	 if( a < 0 ) { 
		 b *= -1;
		 a = abs(a);
		 return;
	 }
	 if( a > c ) {
		 a = c - (a-c);
		 b *= -1;
		 return;
	 }
	 assert( a - c <= 0 ) ; 
	 assert( a >= 0 ); 
	 if( a == c || a == 0 ) b *= -1;
}
		 

void solve(){
	int l , h ; cin >> l >> h ;
	
	int x , y ; cin >> x >> y ;
	int vx, vy ; cin >> vx >> vy ;
	int k; cin >> k ;
	if( vx == 0 && vy == 0 ) {
		cout << x << " " << y << endl;
		return;
	}
	for(int i = 0 ;i < k ; i++ ) {
		int mvx = moves(x,vx,l) ;
		int mvy = moves(y,vy,h) ;
		mvx = min(mvx,mvy);
		//if ( mvx == 0 ) i--; 
		//assert(mvx >0 ) ;
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

