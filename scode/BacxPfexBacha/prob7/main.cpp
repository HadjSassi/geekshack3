//YOU WILL MAKE IT
#include<bits/stdc++.h>


using namespace std;
vector<pair<long long,long long>> v;
long long memo[6001][6002];
int op,n;
long long dp(int i,int j){
    if(j>=op){
        return 0;
    }
    if(i==n){
       return 1e18;
    }
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    memo[i][j]=1e18;
    memo[i][j]=min(dp(i+1,j+2)+v[i].second,min(dp(i+1,j+1)+v[i].first,dp(i+1,j)));
    return memo[i][j];
}

void solve(){
  cin>>n>>op;
  memset(memo,-1,sizeof(memo));
  for(int i=0;i<n;i++){
     long long  a,b;cin>>a>>b;
     v.push_back({a,b});
  }
  cout<<dp(0,0);
}

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
 