
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
// vector<int> ans;
int poss[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int a[N][N];
// bool visited[N][N]; 
ll c;

void solve(){
  ll ans=0,n,b,k,m,x,y;
  string s;
    string data;
    getline(cin,data);
    stringstream dataa_stream(data);

    while(dataa_stream>>n){
        
    }
  
//   vector<int> ans;
    memset(a,0,sizeof(a));
    // memset(visited,false,sizeof(visited));
  for(int i=0;i<n;i++){
    getline(cin,data);
    stringstream data_stream(data);

    int j=0;
    while(data_stream>>b){
        a[i][j]=b;
        j++;
    }
    m=j;
  }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            vector<int> poss;
            poss.push_back(a[i][j]);
            poss.push_back(a[i+1][j]);
            poss.push_back(a[i+1][j+1]);
            poss.push_back(a[i][j+1]);
            int k=1;
            bool ok=false;
            for(int i=0;i<4;i++){
            bool tmp=true;
            for(int j=0;j<4;j++){
                if(poss[(i+j)%4]!=j+1){
                    tmp=false; 
                    break;
                }
            }
            ok|=tmp;
            }
            reverse(poss.begin(),poss.end());

            for(int i=0;i<4;i++){
            bool tmp=true;
            for(int j=0;j<4;j++){
                if(poss[(i+j)%4]!=j+1){
                    tmp=false; 
                    break;
                }
            }
            ok|=tmp;
            }
            if(ok){
                ans++;
            }
        }
    }
  
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