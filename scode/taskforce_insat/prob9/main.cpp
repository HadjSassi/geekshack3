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
            
    int n ,w ; 
    cin>>n>>w ; 
    int a[n]; 
    bitset<100000> all(0);
    for(int i = 0 ;i<n ; i++){
        cin>>a[i];
        for(int j=0;j<w;j++){
          all[a[i]+j]=true;
        }
    }
    cout<<all.count()<<endl;
}
catch (std::ios_base::failure &fail) {
	cout<<"NO"<<endl;
}
}