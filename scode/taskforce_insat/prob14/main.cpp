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
    string ll,ww ,ssz,nnb; 
    int l,w,sz,nb;
    cin>>ll>>ww>>ssz>>nnb ;
    l=stoi(ll);
    w=stoi(ww);           
    sz=stoi(ssz);           
    nb=stoi(nnb);       
        if(nb<=(l/(sz+1))){
            cout<<nb*4<<endl;
        }else{
            cout<<nb*4-2*(nb-l/(sz+1))<<endl;

        }
    }
catch (exception &err) {
	cout<<"INPUT_ERROR"<<endl;
}
}