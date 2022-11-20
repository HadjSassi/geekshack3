#include<bits/stdc++.h>
using namespace std;


void solve(){
    int tt;
    cin >> tt;
    int sum = 0;
    while(tt--){

        int nb,s;

        cin >> nb >> s;
        if(s==0){
            cout<<"NO"<<endl;
            return;
        }
        vector<int> pushes;
        for(int i = 0; i<nb; ++i){
            int x;
            cin >> x;
            pushes.push_back(x);
        }
        for(int i = 1; i<pushes.size(); ++i){
            sum += min(s,pushes[i]-pushes[i-1]);
        }
        
        sum += s;
    
    }
    cout << sum << '\n';
    
}


int main(){
    solve();
} 