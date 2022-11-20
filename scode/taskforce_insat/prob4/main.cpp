
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
map<string,vector<int>> ans;
int poss[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

char a[N][N];
bool visited[N][N]; 
ll c;

void dfs(int fromx,int fromy,char cc){
    if(fromx<0||fromy<0||visited[fromx][fromy]||a[fromx][fromy]!=cc){
        return;
    }
    visited[fromx][fromy]=true;
    c++;
    for(int i=0;i<4;i++){
        dfs(fromx+poss[i][0],fromy+poss[i][1],cc);
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
  
//   vector<int> ans;
    memset(a,false,sizeof(a));
    memset(visited,false,sizeof(visited));
  for(int i=0;i<n;i++){
    // fetdata;
    getline(cin,data);
    stringstream data_stream(data);
    // data.clear();
    // data_stream<<data;
    int j=0;
    char cc;
    while(data_stream>>cc){
        if(cc=='0'||cc=='S'||cc=='T'){
            a[i][j]=cc;
            j++;
        }
    }
    m=j;
    
  }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((a[i][j]=='S'||a[i][j]=='T')&&!visited[i][j]){
                c=0;
                dfs(i,j,a[i][j]);
                if(a[i][j]=='S'){
                    ans["S"].push_back(c);

                }else{
                ans["T"].push_back(c);

                }
            }
        }
    }
    sort(ans["S"].begin(),ans["S"].end());
    sort(ans["T"].begin(),ans["T"].end());
    cout<<"S ";

//   for(auto & i:ans["S"]){
  for(int i=0;i<ans["S"].size();i++){
    cout<<ans["S"][i]*100<<(i<ans["S"].size()-1?' ':'\n');
    // cout<<i*100<<' ';
  }

    cout<<"T ";
  for(int i=0;i<ans["T"].size();i++){
    cout<<ans["T"][i]*100<<(i<ans["T"].size()-1?' ':'\n');
  }
    // cout<<endl;
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