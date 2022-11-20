
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
  ll sum,n,b,k,m,x,y;
  string s;
  try{
    cin>>s;
    n=s.size();
    map<char,int> poss;
    vector<string> ans;
    bool used[100000];
    memset(used,false,sizeof(used));
    for(int from=0;from<n;from++){
      if(!used[from]&&(s[from]==39 ||s[from]==34 ||s[from]==96 ||s[from]=='(' ||s[from]=='[' ||s[from]=='{')){
      used[from]=true;
      int tmp=1;
        for(int sz =1;sz+from<n;sz++){
          if((s[from]==39 ||s[from]==34 ||s[from]==96)
            && (s[from+sz]==s[from])){
              tmp++;
              tmp%=2;
              if(tmp==0){
                ans.push_back(s.substr(from,sz+1)); used[from+sz]=true;
                break;
              }
          }else if( s[from]=='(' ){
              if(s[from+sz]=='('){
                tmp++;
              }else if(s[from+sz]==')'){
                tmp--;
                if(tmp==0){
                  ans.push_back(s.substr(from,sz+1)); used[from+sz]=true;
                  break;
                }
              }
          }else if( s[from]=='[' ){
              if(s[from+sz]=='['){
                tmp++;
              }else if(s[from+sz]==']'){
                tmp--;
                if(tmp==0){
                  ans.push_back(s.substr(from,sz+1)); used[from+sz]=true;
                  break;
                }
              }
          }else if( s[from]=='{' ){
              if(s[from+sz]=='{'){
                tmp++;
              }else if(s[from+sz]=='}'){
                tmp--;
                if(tmp==0){
                  ans.push_back(s.substr(from,sz+1)); used[from+sz]=true;
                  break;
                }
              }
          }

          
        }
      }
    }
    if(ans.empty()){
      cout<<"SYNTAX_ERROR"<<endl;
    }else{
      for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<(i!=ans.size()-1?' ':'\n');
      }
    }
  } catch (std::ios_base::failure &fail) {
    cout << "SYNTAX_ERROR" << endl;
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