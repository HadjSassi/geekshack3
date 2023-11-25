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

ll stoii(string s){
	ll val = 0 ;
	for(int i = 0 ;i < s.size();i++){
		val *= 10;
		val += s[i]-'0';
	}
	return val;
}

void solve(){
	  string s;
 string t;
 getline(cin,t);
 int tt = stoii(t);
	
 for(int p = 0 ;p < tt;p++ ){	
	  //vector < int > vec2; 
	  getline(cin, s);
	  s += " ";
	  int val = 0, coef = 1;
	  vector<int> vec;
	  for(char c : s){
		if(c == '-') coef = -1;
		else if(c == ' '){
		  vec.push_back(coef * val);
		  val = 0;
		  coef = 1;
		}
		else{
		  val = val*10 + (c-'0');
		}
	  }
	  s = "";
	  getline(cin, s);
	  s += " ";

	  vector<int> vec2;
	  for(char c : s){
		if(c == '-') coef = -1;
		else if(c == ' '){
		  vec2.push_back(coef * val);
		  val = 0;
		  coef = 1;
		}
		else{
		  val = val*10 + (c-'0');
		}
	  }
	  int n = vec.size()-1;
	  for(int j = 0 ; j< vec2.size(); j++ ) {
		 ll x = vec2[j];
		 ll ans = 0 ;
		 int nn = n;
		 for(int i = 0 ;i < vec.size() ; i++ ) { 
			ans += vec[i]*powl(x,nn);
			nn--;
		 }
		 cout << ans;
		 if( j == vec2.size()-1) continue;
		 cout << " ";
	 }
	 if( p == tt-1 ) continue;
	 cout << endl;
  }
		
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

 
