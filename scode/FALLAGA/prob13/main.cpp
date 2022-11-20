#include<bits/stdc++.h>
using namespace std;
int p[100] ;
int eff[100] ;
int b , n ;
int res(int pos ,int budget ,int  nbrmachineleft  ){
    if(pos == n) return 0 ;
    if(nbrmachineleft !=0 && budget >= p[pos] ){
        return max((eff[pos] + res(pos , budget-p[pos] , nbrmachineleft-1  )) , res(pos+1 , budget , 2  )) ;
    }else{
        return  res(pos+1 , budget , 2  ) ;
    }
}
void solve(){

    cin >> b >> n ;
    int price ,effi ;
    for(int i=0 ; i<n ; i++){
        cin >> price >> effi ;
        p[i] = price;
        eff[i] = effi ;
    }
    cout << res(0,b,2) ;
}

int main(){
    solve();
}


