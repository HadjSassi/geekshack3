
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

bool a[N][N];
bool visited[N][N]; 
ll c;



void solve(){
  ll ans=0,sum,n,b,k,m,x,y;
  string s;
  try{
    cin>>sum>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    ll dp[200000];
    memset(dp,0,sizeof(dp));
    // dp[0]=sum;
    for(int i=0;i<n;i++){
        for(int j=0;j<sum;j++){
            if(j==0||dp[j]>=a[i]){
                dp[j+a[i]]=max(dp[j+a[i]],dp[j]+b[i]);
                dp[j+2*a[i]]=max(dp[j+2*a[i]],dp[j]+2*b[i]);
            }
        }
        // dp|=(dp<<1*b[i])|(dp<<2*b[i]);
    }
    
    for(int i=sum;i>=0;i--){
        ans=max(dp[i],ans);
    }
    cout<<ans<<endl;

  } catch (std::ios_base::failure &fail) {
    cout << "INPUT_ERROR" << endl;
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