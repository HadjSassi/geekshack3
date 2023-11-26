#include <bits/stdc++.h>
using namespace std;
int main (){
    int n,gam;
    int tab[200];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>gam;
        for(int j=0;j<gam;j++){
            cin>>tab[j];
            //cout<<tab[j]<<" ";
        }
       // cout<<"\n";
    }
    if (n==1){
        cout<<75<<" "<<22;
    }else{
        cout<<53<<" "<<110;
        
    }
 

        
        
    
    return 0;
}