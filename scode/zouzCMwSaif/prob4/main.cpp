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
const ld INF = 1e10;

void solve(){
	ld l , h ; cin >> l >> h ;
	ld x , y ; cin >> x >> y ;
	ld vx, vy ; cin >> vx >> vy ;
	ld k; cin >> k ;
	if( (vx == 0 && vy == 0)  || k == 0 ) {
		cout << x << " " << y << endl;
		return;
	}
	//k--;
	while( k != 0 ) {
	    ld b = INF ;
	    ld a = INF ;
	    //cout << vx << " " << vy << endl;
	    if( vy > 0 ){
	        b = h-y;
		    b /= vy ;     
	    }
	    if( vy < 0 ){
	        b = y;
	        b /= vy;
	    }
	    if( vx > 0 ){
	        a = l-x;
		    a /= vx ;    
	    }
	    if( vx < 0 ){
	        a = x;
	        a /= vx;
	    }
	    a = abs(a);
	    b = abs(b);
	    //cout << "b" <<  b << " " << a << endl;
	    if( b < a ){
	        y += vy*b;
	        x += vx*b;
	        vy *= -1;
	    }
	    else if( a < b ) { 
	        x += vx*a;
	        y += vy*a;
	        vx *= -1;
	    }else {
	        x += vx*a;
	        y += vy*a;
	        vx *= -1;
	        vy *= -1;
	    }
		k--;
	//	cout << x << " " << y << endl;
	}
	cout << floor(x) << " " << floor(y) << endl;
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


