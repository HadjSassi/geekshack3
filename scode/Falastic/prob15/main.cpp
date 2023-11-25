#include<bits/stdc++.h>
using namespace std;
typedef long long  ll; 

void solve(){
	int min,max;cin>>min>>max;
	int ans=0;
	int nbit1=round(log2(min)),nbit2=round(log2(max));
	for (int i=nbit1;i<=nbit2;i++){
		int k=0,n=pow(2,i)-1;
		while (min<=n-pow(2,k) && k<i){
			if (n-pow(2,k)<=max){
				ans++;
			}
			k++;
		}
	}
	cout <<ans;
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