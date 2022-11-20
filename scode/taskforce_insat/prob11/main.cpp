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
	cin.tie(0);
  string s ; 
  int cnt = 0 ; 
 while( cin>>s) { 
     if(cnt){cout<<" ";}
     cnt++;
		for(auto i:s){
			if(i<'0'||i>'9'){
				cout << "NOT_CLEAR";
            	return 0;
			}
		}
        int a = stoi(s);
        int f = 0 ; 
       if((a & 8)==8){
           cout<<"declare_your_position";
           f++;
       }
          if((a&4)==4){
            if(f){cout<<" ";f++;}
           cout<<"need_backup";
           f++;
       }
        if((a&2)==2){
            if(f){cout<<" ";f++;}
           cout<<"run";
           f++;
       }
          if((a&1)==1){
              if(f){cout<<" ";f++;}
           cout<<"take_position";
           f++;
       }



}}