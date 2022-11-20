//seg tree without lazy propagation 

#include<bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = (x); i <= (y); i++)
#define forr(i, x, y) for (int i = (x); i < (y); i++)
#define forrl(i, x, y) for (ll i = (x); i < (y); i++)
#define dow(i, x, y) for (int i = (x); i >= (y); i--)

#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+5;
vector<int> nodes[N];


void solve(){
  ll ans,n,k,m,x,y;
  string s,b,data;
  getline(cin,data);
  if(data.size()==0||(data[0]<'0'||data[0]>'9')){
    cout<<"NO"<<endl;
    return;
  }
  n=stoi(data);
  if(n==0){
    cout<<"NO"<<endl;
    return;
  }
  // cin>>n;
  map<string,unordered_set<string>> all;
  for(int i=0;i<n;i++){
    cin>>s>>b;
    getline(std::cin,data);
    int ii=0,jj=data.size();
    while(data[ii]==' '){
      ii++;
      jj--;
    }
    while(data[jj]==' '){
      jj--;
    }
    data=data.substr(ii,jj);
    if(jj>0&&data.size()){
    all[b].insert(data);

    }
  }
  // all["Main"].insert("A");
  // if(all["Main"].find("A")==all["Main"].end()){
  //   cout<<"not her"<<endl;
  // }  
  // if(all["Main"].find("B A")==all["Main"].end()){
  //   cout<<"B not her"<<endl;
  // } 
  all["Main"];
  all["A"];
  all["B"];
  for(auto &i: all["A"]){
    bool ok=false;
    if(all["Main"].find(i)==all["Main"].end()){
    for(auto &k: all["Main"]){
      //size of A
      int m=0;
      for(int r=0;r<k.size();r++){
        while(m<i.size()&&i[m]!=k[r]){
          m++;
        }
      }
      if(m<i.size()){
        string tmp=i+" : M";
        ok=true;
        all["Main"].erase(k);
        all["Main"].insert(tmp);
        break;
      }
    }
    if(!ok){
        all["Main"].insert(i+" : U");
    }
    }else{
        all["Main"].insert(i);
    }
  }
  for(auto &i: all["B"]){
    bool ok=false;
    if(all["Main"].find(i)==all["Main"].end()){
    for(auto &k: all["Main"]){
      //size of A
      int m=0;
      for(int r=0;r<k.size();r++){
        while(m<i.size()&&i[m]!=k[r]){
          m++;
        }
      }
      if(m<i.size()){
        string tmp=i+" : M";
        ok=true;
        all["Main"].erase(k);
        all["Main"].insert(tmp);
        break;
      }
    }
    if(!ok){
        all["Main"].insert(i+" : U");
    }
    }else{
        all["Main"].insert(i);
    }
  }
  map<string,unordered_set<string>> res;
  for(auto j:all["Main"]){
    if(j.back()=='M'){
      res["M"].insert(j);
    }else if(j.back()=='U'){
      res["U"].insert(j);

    }else{
      res[" "].insert(j);

    }
    // cout<<j<<endl;
  }
  for(auto j:res["M"]){
    cout<<j<<endl;
  }
  for(auto j:res["U"]){
    cout<<j<<endl;
  }
  for(auto j:res[" "]){
    cout<<j<<endl;
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