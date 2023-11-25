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

int n; 
int m;
int s;

vector < pair < int ,int >  > adj[N];

void solve(){
	int n; cin >> n;
	char c ; cin >> c;
	string s; cin >> s;
	if (c == 'E' ) { 
		for(int i = n ; i >= 1 ; i-- ){
			if( n%i == 0 )
				reverse(s.begin(),s.begin()+i); 
		}	
		//cout << s << endl;
	}else{
		for(int i = 1 ; i <= n ; i++ ){
			if( n%i == 0 )
				reverse(s.begin(),s.begin()+i); 
		}	
	}
	cout << s << endl;
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

