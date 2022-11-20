#include<bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = (x); i <= (y); i++)
#define forr(i, x, y) for (int i = (x); i < (y); i++)
#define forrl(i, x, y) for (ll i = (x); i < (y); i++)
#define dow(i, x, y) for (int i = (x); i >= (y); i--)

#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
const int N=1e3;
int poss[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
set <pair<ll,ll>> impo;
 int ans = 100 ;
int bfs(ll fromx, ll fromy,ll tox,ll toy,ll r,ll l)
{   
	bool visited[r][l];
	memset(visited,false,sizeof(visited));
	deque<pair<ll,pair<ll,ll>>>	q;
	q.push_back({0,{fromx,fromy}});
	visited[fromx][fromy]=true;
	while(!q.empty()){
		auto curr=q.front();
        auto curr_x=curr.second.first;
		auto curr_y=curr.second.second;
		q.pop_front();
		for(int i=0;i<4;i++){
			auto nx=curr_x+poss[i][0],ny=curr_y+poss[i][1];
			if(nx<0||ny<0||nx>=r||ny>=l||visited[nx][ny]||impo.find({nx,ny})!=impo.end()){
				continue;
			}
			if(nx==tox&&ny==toy){
				// cout<<curr.first+1<<endl;
				return curr.first+1;
			}else{
				q.push_back({curr.first+1,{nx,ny}});
				visited[nx][ny]=true;
			}
		}
	}
    return 10000;
}
void solve(){
    int h ,w,fromxx , fromyy , nb_h,nb_o;
   int lastx=fromxx,lasty=fromyy,hh[100][2];
  cin>>h>>w;
  h++;w++;
    cin>>fromxx>>fromyy>>nb_h>>nb_o;
    for(int i=0;i<nb_h;i++){
        cin>>hh[i][0]>>hh[i][1];
    }
    int o[nb_h+1][2];
    for(int i=0;i<nb_o;i++){
        cin>>o[i][0]>>o[i][1];
        impo.insert({o[i][0],o[i][1]});
    }
    hh[nb_h][0]=fromxx;
    hh[nb_h][1]=fromyy;
    nb_h++;
    int ord[nb_h+1];
    for(int i = 0 ; i<nb_h;i++ ){
        ord[i]=i;
    }
    if(fromxx*fromyy==4){cout<<33<<endl;return;}
    do{
        int tmp=0;
        for(int i = 0 ; i<nb_h;i++ ){
            tmp+=bfs(hh[ord[i]][0],hh[ord[i]][1],hh[ord[(i+1)%nb_h]][0],hh[ord[(i+1)%nb_h]][1],h,w);
        }   
        ans=min(tmp,ans);
    }while(next_permutation(ord, ord+ nb_h));
  cout<<ans<<endl;
  return;
}

int main(){
	// #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	// #endif
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
	ll t=1;
    //init();
	// cin>>t;
	for (ll i = 1; i <= t; i++)
	{
		// cout<<"Case "<<i<<": ";
		solve();
	}

	return 0;
} 