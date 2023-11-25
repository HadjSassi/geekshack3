#include<bits/stdc++.h>
using namespace std;
typedef long long  ll; 
void solve(){
	int n ;cin >>n ; 
	char c; cin>>c;
	string s;cin >>s;
	if (c=='E'){
		reverse(s.begin(),s.end());
		for (int i=n/2;i>=1;i--){
			if (n%i==0){
				reverse(s.begin(),s.begin()+i);
			}
		}
		cout<<s;		
	}else {
		for (int i=1;i<=n/2;i++){
			if (n%i==0){
				reverse(s.begin(),s.begin()+i);
			}
		}
		reverse(s.begin(),s.end());
		cout<<s;
	}
} 
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    solve();
	return 0;
}	