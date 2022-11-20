
#include<bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = (x); i <= (y); i++)
#define forr(i, x, y) for (int i = (x); i < (y); i++)
#define forrl(i, x, y) for (ll i = (x); i < (y); i++)
#define dow(i, x, y) for (int i = (x); i >= (y); i--)

#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+5;
vector<int> nodes[N];


void solve(){
  ll ans,n,k,b,m,x,y;
  ll sum_tickets=0,sum_gas=0;
  string s;
  ll N,F,T,A;
  cin>>N>>F>>T>>A;
  vector<pair<int,int>>  stations,forward,backward;
  ll D_i,C_i,Nb_iA,P_iA,Nb_iR,P_iR;
  ll memD,memP;
  for(int i=0;i<N;i++){
      cin>>D_i>>C_i;
      forward.push_back({D_i,C_i});
      cin>>D_i>>C_i;
      backward.push_back({D_i,C_i});
      if(i==0){
          backward[0].first*=2;
      }
  }
  stations.push_back({0,0});
  stations.insert(stations.end(),forward.begin(),forward.end());
  stations.insert(stations.end(),backward.begin(),backward.end());
  stations.push_back({forward[0].first,0});
  //stations[1].first==8?stations[1].first-=6:stations[0].first;
    set<pair<pair<ll,ll>,ll>> price_dist_index;
  for(int i=0;i<stations.size();i++){
      ll dist=0,tmp=F;
      ll j=i;
      for(j=i+1;j<stations.size();j++){
        dist+=stations[j].first;
        if(dist>T){
            break;
        }
        price_dist_index.insert({{stations[j].second,dist},j});
      }
      if(price_dist_index.empty()&&i!=stations.size()-1){
          cout<<-1<<endl;
          return;
      }
      auto least=*price_dist_index.begin();
      
      sum_gas+=(least.first.first*(F-T+least.first.second));
      T=F;
      if(least.second==stations.size()-1){
          break;
      }
      i=least.second-1;
      price_dist_index.clear();
  }
  
  
  
  
  for(int i=0;i<A;i++){
    cin>>Nb_iA>>P_iA>>Nb_iR>>P_iR;
    sum_tickets+=Nb_iA*P_iA;
    sum_tickets+=Nb_iR*P_iR;
  }

  cout<<sum_gas<<endl<<sum_tickets<<endl<<sum_tickets-sum_gas<<endl;

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