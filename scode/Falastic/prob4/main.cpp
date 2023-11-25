#include<bits/stdc++.h>
using namespace std;
typedef long long  ll; 
void solve(){
	int l,h,x,y,vx,vy,k;
	cin>>l>>h>>x>>y>>vx>>vy>>k;
	int i=0;
	while (i<k){
			x+=vx;
			y+=vy;
			if (x<=0){
				x=0;
				vx*=-1;
				i++;
			}else if (x>=l){
				x=l;
				vx*=-1;
				i++;
			}
			if (y<=0){
				y=0;
				vy*=-1;
				i++;				
			}else if (y>=h){
				y=h;
				vy*=-1;
				i++;
			}		
	}
	cout <<x<<" "<<y;
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