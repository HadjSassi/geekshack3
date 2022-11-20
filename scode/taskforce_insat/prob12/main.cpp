#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for (int i = a; i < b; i++)
int o[1000][1000];
int r, l, x1, yy, x2, y2,maxi=1e8;
set <pair<ll,ll>> impo;
int poss[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};


bool ok;
void bfs(ll fromx, ll fromy,ll tox,ll toy,ll r,ll l)
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
		for(int i=0;i<8;i++){
			auto nx=curr_x+poss[i][0],ny=curr_y+poss[i][1];
			if(nx<0||ny<0||nx>=r||ny>=l||visited[nx][ny]||impo.find({nx,ny})!=impo.end()){
				continue;
			}
			if(nx==tox&&ny==toy){
				cout<<curr.first+1<<endl;
				ok=true;
				return;
			}else{
				q.push_back({curr.first+1,{nx,ny}});
				visited[nx][ny]=true;
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> l;
    cin >> x1 >> yy >> x2 >> y2;
    if (x1<0||x2<0||y1<0||y2<0||x1 > r - 1 || yy > l - 1 || x2 > r - 1 || y2 > l - 1)
    {
        cout << "INPUT_ERROR";
        return 0;
    }
    ll n;
    cin >> n;
    memset(o, 0, sizeof(o));
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        string s1,s2;
		cin >> s1>> s2;
		for(auto i:s1){
			if(i<'0'||i>'9'){
				cout << "INPUT_ERROR";
            	return 0;
			}
		}		
		for(auto i:s2){
			if(i<'0'||i>'9'){
				cout << "INPUT_ERROR";
            	return 0;
			}
		}		
		a=stoi(s1);
		b=stoi(s2);
		
        if (a<0||b<0||a >= r || b >= l )
        {
            cout << "INPUT_ERROR";
            return 0;
        }
		impo.insert({a,b});

    }
	ok=false;
	bfs(x1,yy,x2,y2,r,l);
	if(!ok){
		cout<<0<<endl;
	}
	return 0;
    
}