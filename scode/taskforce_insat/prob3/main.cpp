
#include<bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = (x); i <= (y); i++)
#define forr(i, x, y) for (int i = (x); i < (y); i++)
#define forrl(i, x, y) for (ll i = (x); i < (y); i++)
#define dow(i, x, y) for (int i = (x); i >= (y); i--)

#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
const int N=1e4;
// vector<int> nodes[N];
vector<int> ans;
int poss[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

bool a[N][N];
bool visited[N][N]; 
ll c;

void dfs(int fromx,int fromy){
    if(fromx<0||fromy<0||visited[fromx][fromy]||!a[fromx][fromy]){
        return;
    }
    visited[fromx][fromy]=true;
    c++;
    for(int i=0;i<4;i++){
        dfs(fromx+poss[i][0],fromy+poss[i][1]);
    }

}

void solve(){
  ll n,b,k,m,x,y;
  string s;
    string data;
    getline(cin,data);
    if(data.size()==0){
       cout<<"NO"<<endl;
       return ;
    }
    for(int i=0;i<data.size();i++){
        if(data[i]<'0'||data[i]>'9'){
            cout<<"NO"<<endl;
        return ;
        }
    }
    n=stoi(data);
  
  vector<int> ans;
    memset(a,false,sizeof(a));
    memset(visited,false,sizeof(visited));
  for(int i=0;i<n;i++){
    // fetdata;
    getline(cin,data);
    stringstream data_stream(data);
    // data.clear();
    // data_stream<<data;
    while(data_stream>>b){
        a[i][b]=true;
    }
    
  }
    for(int i=0;i<n;i++){
        for(int j=0;j<N;j++){
            if(a[i][j]&&!visited[i][j]){
                c=0;
                dfs(i,j);
                ans.push_back(c);
            }
        }
    }
    sort(ans.begin(),ans.end());
  for(auto & i:ans){
    cout<<i*100<<endl;
  }
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