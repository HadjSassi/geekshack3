#include <bits/stdc++.h>
#include <map>
#include <string>
using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int y;
    ll bash=0,mab=0;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        for(int j=0;j<x/2+x%2;j++){
            cin>>y;
            bash+=y;
        }
        for(int j=0;j<x/2;j++) {
            cin>>y;
            mab+=y;
        }
    }
    cout<<bash<<" "<<mab<<endl;
}
