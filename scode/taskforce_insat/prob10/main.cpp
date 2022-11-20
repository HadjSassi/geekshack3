#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);try {
            string tt ; 
            int t;
            cin>>tt ;
            t=stoi(tt);
            int ans = 0 ; 
            while(t--){
                    string nn ,ww ; 
                    int n ,w ; 
    cin>>nn>>ww ; 
    n=stoi(nn);
    w=stoi(ww);
    int a[n]; 
    bitset<100000> all(0);
    for(int i = 0 ;i<n ; i++){
        cin>>a[i];
        for(int j=0;j<w;j++){
          all[a[i]+j]=true;
        }
    }
    ans+=all.count();
            }
            cout<<ans<<endl;
    }
catch (exception &err) {
	cout<<"NO"<<endl;
}
}