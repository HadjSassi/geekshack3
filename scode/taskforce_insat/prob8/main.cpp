
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
    int a[4];
      int i=0;
      while(cin>>a[i]){
          i++;
      }
      if(i<4){
          cout<<"NO"<<endl;
          return;
      }
    // cin>>aa[0]>>aa[1]>>aa[2]>>aa[3];
    sort(a,a+4);
    cout<<a[0]*a[2]<<endl;

  } catch (std::ios_base::failure &fail) {
    cout << "NO" << endl;
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