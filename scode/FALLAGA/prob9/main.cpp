#include<bits/stdc++.h>
using namespace std;

int t[100][100] ;

int v[100] ;
void solve(){
    int n ,k, len ;
    cin >> n >> len ;
    for(int i=0 ; i<n ; i++){
        cin >> k ;
        for(int j=k ; j<k+len ; j++){
            v[j] = 1 ;
        }
    }
    int s =0 ;

    for(int i =0 ; i<100 ; i++){
        s+= v[i] ;
    }
cout << s ;
}

int main(){
    solve();
}


