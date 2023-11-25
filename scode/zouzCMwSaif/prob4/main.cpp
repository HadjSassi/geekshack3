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

void calc(int &a , int &b , int c  ) {
	if( b > 0 ) {
		int diff = c-a;
		int bb = diff-b;
		if( bb < 0  ) {
			a = c+bb;
			b *= -1;
			return;
		}else {
			a += b; 
			return;
		}
	}
	else {
		int bb = a + b; 
		if( bb < 0 ) { 
			a = abs(bb);
			b*=-1;
			return;
		}else {
			a = bb;
		}
	}
}
		 

void solve(){
	int l , h ; cin >> l >> h ;
	
	int x , y ; cin >> x >> y ;
	int vx, vy ; cin >> vx >> vy ;
	int k; cin >> k ;
	for(int i = 0 ;i < k ; i++ ) {
		calc(x,vx,l);
		calc(y,vy,h);
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

