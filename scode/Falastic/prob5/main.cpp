#include<bits/stdc++.h>
using namespace std;
typedef long long  ll; 

void solve(){
	string p1,p2,p3;
	cin>>p1>>p2>>p3;
	if ((p1[1]==p2[1] && p1[1]==p3[1] )||(p1[2]==p2[2] && p1[2]==p3[2]))	cout <<"NO";
	else cout <<"YES";
	

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