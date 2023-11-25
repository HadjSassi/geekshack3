#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using orderded_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)
#define PB push_back
#define fr(i,a,b) for(ll i = a; i < b; i++)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define F first
#define S second
 
 
typedef vector<ll>vll ;
typedef pair<ll,ll>pll;
 
/*-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------*/
 
ll mod=1e9+7; 
const int N=1e7 + 5;
 
bool prime[N];
int spf[N];
 
 
ll add(ll x,ll y){ll res=x+y ; return(res>=mod?res-mod:res);}
ll mul(ll x,ll y){ll res=(x%mod)*(y%mod) ; return(res>=mod?res%mod:res);}
ll sub(ll x,ll y){ll res=x-y ; return(res<0?res+mod:res);}
ll power(ll x, ll y) {if (y < 0) return 1; ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll inv(ll x){return power(x,mod-2);}
 
void seive(){
  for(int i=0;i<N;i++){spf[i]=i;}
  fill(prime,prime+N,true);
  prime[0]=prime[1]=false;
  for(int i=2;i*i<=N;i++){
    if(prime[i]==true){
      for(int j=i*i;j<N;j+=i){
        prime[j]=false;
        if(spf[j]==j)spf[j]=i;
      }
    }
  }
}
 
int fact[N],invfact[N];
void initNCR(){
    fact[0]=1;
    int i;
    for(i=1;i<N;i++){
        fact[i]=mul(i,fact[i-1]);
    }
    i--;
    invfact[i]=power(fact[i],mod-2);
    for(i--;i>=0;i--){
        invfact[i]=mul((i+1),invfact[i+1]);
    }
}
int  ncr(int n,int r){
    if(r>n || n<0 || r<0)return 0;
    return mul(mul(fact[n],invfact[r]),invfact[n-r]);
}
 
bool comp(pair<int , int> a, pair<int,int>b){
    if(a.first!=b.first)
    {return a.first>b.first;}
    else return a.second>b.second;
}
 
 
/*-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------*/
 
ll n,m,i1,jj,i2,j2,d;
map<string,ll>mp;
 
bool meet(){
  int x,y;
  if(d==1){
    x=j2-jj;
    y=i1-i2;
    if(x>=0 && y>=0 && x<m && y<n && x==y )return true;
    return false;
  }
  else if(d==2){
    x=j2-jj;
    y=i2-i1;
    if(x>=0 && y>=0 && x<m && y<n && x==y )return true;
    return false;
  }
  else if(d==3){
    x=jj-j2;
    y=i2-i1;
    if(x>=0 && y>=0 && x<m && y<n && x==y )return true;
    return false;
  }
  else{
    x=jj-j2;
    y=i1-i2;
    if(x>=0 && y>=0 && x<m && y<n && x==y )return true;
    return false;
  }
}
 
void nextCoordinate(){
  if(d==1){
    ll y=abs(i1-1);
    ll x=abs(jj-m);
    i1-=min(x,y);
    jj+=min(x,y);
    if(x==y){
      d=3;
    }
    else if(x<y){
      d=4;
    }
    else d=2;
  }
  else if(d==2){
    ll y=abs(i1-n);
    ll x=abs(jj-m);
    i1+=min(x,y);
    jj+=min(x,y);
    if(x==y){
      d=4;
    }
    else if(x<y){
      d=3;
    }
    else d=1; 
  }
  else if(d==3){
    ll y=abs(i1-n);
    ll x=abs(jj-1);
    i1+=min(x,y);
    jj-=min(x,y);
    if(x==y){
      d=1;
    }
    else if(x<y){
      d=2;
    }
    else d=4;
  }
  else{
    ll y=abs(i1-1);
    ll x=abs(jj-1);
    i1-=min(x,y);
    jj-=min(x,y);
    if(x==y){
      d=2;
    }
    else if(x<y){
      d=1;
    }
    else d=3;
 
  }
}
 
int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  mp["UR"]=1;
  mp["DR"]=2;
  mp["DL"]=3;
  mp["UL"]=4;
  while(t--){
    cin>>n>>m>>i1>>jj>>i2>>j2;
    string dir;
    cin>>dir;
    map<vll,ll>vis;//i,j,dir
    queue<vll>q;
    q.push({i1,jj,mp[dir]});
    ll level=0;
    while(q.size()){
      auto f=q.front();
      i1=f[0];
      jj=f[1];
      d=f[2];
      q.pop();
      if(meet()){
        break;
      }
      if(vis[{i1,jj,d}]){
        level=-1;
        break;
      }
      vis[{i1,jj,d}]=1;
      nextCoordinate();
      q.push({i1,jj,d});
      level++;
    }
    cout<<level<<endl;
 
  }
 
}
 