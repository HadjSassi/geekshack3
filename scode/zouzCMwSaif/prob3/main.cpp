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
	string s; 
	getline(cin,s);
	int n = (int)s.size();
	ll ans = 0 ;
	string t = "" ;
	int sz = 0 ;
	string p = "chak";
	string l = "chouka";
	for(int i = 0 ; i < n;i++){
		t += s[i];
		if( t[sz] != p[sz] ) {
			if( s[i] == p[0] ){
				t = s[i];
				sz = 1;
				continue;
			}
			else t = "";
			sz = 0;
			continue;
		}
		
		sz++;
		int szz = 0 ;
		//cout << i << " " << t << endl;
		if( sz == 4 ) { 
			
			string st = "";
			for(int j = i+1;  j <  n ; j++ ) {
					st += s[j];
					if( st[szz] != l[szz] ) {
						if( s[j] == l[0] ){
							st = s[j];
							szz = 1;
							continue;
						}
						else st = "";
						szz = 0;
						continue;
					}
					szz++ ; 
					if( szz == 6 ) {
						szz = 0 ;
						ans++ ;
						st = "";
					} 
			}
			sz = 0 ;
			t = "";
		}
	}
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
