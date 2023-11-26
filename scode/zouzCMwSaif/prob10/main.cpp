#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0)//, cout.tie(0)
#define ll long long
#define ld long double
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"
const ld pi = 3.141592653;
using namespace std;
const ll MOD = 1e8;
const int N = 1e5 + 5;
const ll INF = 1e18; 

ld calc(ll x1, ll y1, ll z1, ll x, ll y , ll z){
	return (x - x1)*(x - x1) + (y - y1)*(y - y1) + (z - z1)*(z - z1);
} 

ld calcAlpha(ld r1, ld r2 , ld d ){
	return acos((r1*r1+d*d-r2*r2)/(2*r1*d));
}

ld calculus(ld r1, ld r2, ld h1 , ld h2 ){
	return ((pi*h1*h1)/3)*(3*r1-h1)+pi*h2*h2*(3*r2-h2)/3;
}

void solve(){
	ld x, y ,z ; cin >> x >> y >> z; 
	ld r1;  cin >> r1 ;
	ld x1 ,y1,z1 ,r2 ; cin >> x1 >> y1 >> z1 >> r2 ;
	ld d = sqrtl(calc(x1,y1,z1, x, y ,z));
	if ( d  <= r2+r1 && d >= abs(r1-r2)   ) {
		ld alpha = calcAlpha(r1,r2,d);
		ld teta  = calcAlpha(r2,r1,d);
		ld h = r1*sin(alpha);
		ld h1 = r1*(1-cos(alpha));
		ld h2 = r2*(1-cos(teta));
		cout << fixed << setprecision(3) ;
		cout << calculus(r1,r2,h1,h2);
	}
	else cout << 0 << endl;
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

 
