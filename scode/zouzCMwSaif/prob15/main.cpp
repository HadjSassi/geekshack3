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

vector <string>v;
string calc(ll x ) {
	string ret = "";
	while( x ) {
		if( x&1 ) ret += "1";
		else ret += "0";
		x /= 2;
	}
	reverse(ret.begin(),ret.end());
	return ret;
} 

void prep(){
	vector <string>vv;
	string s = "";
	for(int i = 0 ; i <= 64 ;i++ ){
		s += "1";
		vv.push_back(s);
	}
	for(int i = 0 ; i <= 64 ; i++ ) {
		string p = vv[i];
		for(int j = 1 ; j <= i ; j++ ){
			p[j] = '0';
			v.push_back(p);
			p[j] = '1';
		} 
	}
}

int check( string &s , string &sx, string &sy){
	if( s.size() > sy.size() ) return 0;
	if( s.size() < sx.size() ) return 0;
	if( s.size() == sy.size() ) { 
		for(int i = 0 ; i < sy.size() ; i++ ){
			if( s[i] > sy[i] )  return 0;
			if( s[i] < sy[i] ) break;
		}
	}
	if( s.size() == sx.size() ) {
		for(int i = 0 ; i< sx.size() ; i++ ){
			if( s[i] > sx[i] ) break;
			if( s[i] < sx[i] ) return 0;
		}
	}
	return 1;
}
void solve(){
	ll x , y ; cin >> x >>  y;
	//vector < string > vv;	
	string sx = calc(x);
	string sy = calc(y);
	int ans = 0;
	//cout << sx << " " << sy << endl;
	for(int i = 0 ; i < v.size(); i++ ){
		//cout << v[i] << " " << sx << " " << sy << endl;
		 ans += check(v[i],sx,sy);
	}
	cout << ans << endl;	
}
                   
                    
int main()
{
	prep();
	//freopen("input.txt","r",stdin); freopen("output.out","w",stdout);
	FAST;
	int t = 1;
	//cin>>t ;
	while (t--)
	{
		solve();
	}
}

