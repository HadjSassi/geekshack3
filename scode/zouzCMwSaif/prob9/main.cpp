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

ld calc(ld a, ld b ,ld c ,ld d){
	return (c-a)*(c-a)+(d-b)*(d-b);
}

string yess(ld x, ld y, vector < pair < ld ,ld >> &vp, ld dist ){
		for(int i = 0 ;i < vp.size(); i++) {
			//cout << calc(x,y,vp[i].first,vp[i].second)<< endl;
			 if( calc(x,y,vp[i].first,vp[i].second) <= dist ) return "NO";
		 }
		 return "YES" ;
}

void solve(){
	int n; cin >> n; 
	int m ; cin >> m; 
	if( n == 2 && m != 2  ){
		 cout << "YES" << endl;
		 return;
	}
	vector < pair < ld ,ld > >vpa,vpb ;
	for(int i = 0; i < n;i++ ){
		int x , y ;cin >> x >> y ;
		vpa.push_back(make_pair(x,y));
	}
	for(int i = 0; i < m;i++ ){
		int x , y ;cin >> x >> y ;
		vpb.push_back(make_pair(x,y));
	}
	ld dist = 0 ;
	int pos1 = 0 , pos2 = 0;
	for(int i = 0 ;i < n;i++) {
		for(int j = i ; j <n ; j++){
			dist = max(dist,calc(vpa[i].first,vpa[i].second,vpa[j].first,vpa[j].second));
			if( dist == calc(vpa[i].first,vpa[i].second,vpa[j].first,vpa[j].second)) {
				pos1 = i;
				pos2 = j;
			}
		}
	}
	ld dist1 = 0 ;
	int pos11 = 0 , pos22 = 0;
	for(int i = 0 ;i < m;i++) {
		for(int j = i ; j <m ; j++){
			dist1 = max(dist1,calc(vpb[i].first,vpb[i].second,vpb[j].first,vpb[j].second));
			if( dist1 == calc(vpb[i].first,vpb[i].second,vpb[j].first,vpb[j].second)){
				pos11 = i;
				pos22 = j;
			}
		}
	}
	assert(pos1 < n) ; assert(pos2 < n);
	assert(pos11 < m) ; assert(pos22 < m);
	 
	ld cx = vpa[pos1].first + vpa[pos2].first;
	cx/=2;
	ld cy = vpa[pos1].second + vpa[pos2].second;
	cy/=2;
	
	ld c2x = vpb[pos11].first + vpb[pos22].first;
	c2x/=2;
	ld c2y = vpb[pos11].second + vpb[pos22].second;
	c2y/=2;
	if(dist < dist1){
		cout << yess(cx,cy,vpb, dist/4) << endl;
	}else {
		cout << yess(c2x,c2y,vpa, dist1/4) << endl;
	}
	//cout << dist << " " << dist1 << endl;
	//cout << cx << " " << cy << endl;
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

 
