#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0)//, cout.tie(0)
#define ll long long
#define ld long double
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"
const ld pi = acos(-1);
using namespace std;
const ll MOD = 1e8;
const int N = 1e3 + 5;
const ll INF = 1e18; 

void solve(){
   string s; cin >> s;
   int n = s.size();
   map < char ,int > mp, mpp;
   //int cnt = 0 ;
   for(int i = 0 ;i < n ; i++ ){
	   mp[s[i]]++;
   }
   sort(s.begin(),s.end());
   int cnt = 0 ;
   vector < char > v; 
  
   for(int i = 0 ;i < n;i++){
	   cnt += mp[s[i]]&1;
	   if( mp[s[i]]&1 && !mpp[s[i]] ) 
	   v.push_back(s[i]),mpp[s[i]]=1;
   }
   sort(v.begin(),v.end());
   int ans = v.size()/2; 
   for(int j= 0 ; j< v.size()/2; j++){
	  mp[v[j]]++;
   }
   for(int j = v.size()/2+v.size()%2; j < v.size() ; j++ ){
	   mp[v[j]]--;
   }
   string left = "";
   string west= "";
   for(int i = 0 ;i < n ; i++ ){
	  // cout << s[i] << " " << mp[s[i]] << endl;
	   if( mp[s[i]] > 1 ) {
		   mp[s[i]]-=2;
		   left += s[i];
	   }
	   else if( mp[s[i]] == 1 ) west += s[i];
   }
   
   string right = left ;
   right += west;
   reverse(left.begin(),left.end());
   right += left;
   //left += west + reverse(left.begin(),left.end());
   cout << right;
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

 
