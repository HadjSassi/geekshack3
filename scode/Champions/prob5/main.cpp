#include <bits/stdc++.h>
using namespace std;
int main (){
    string posR,posW,posK;
    for (int i=0;i<2;i++){
        if (posW[2]==posK[2] && posR[1]!=posW[1]+1 &&posR[2]>=posW[2]+2){
            cout<<"YES";
            break;
        }else if(posW[2]==posK[2] && posR[1]!=posW[1]+1 &&posR[2]<=posW[2]+2){
            cout<<"YES";
            break;
        }else if(posW[2]-posK[2]==1 && posR[2]>=posW[2]+2 && posR[1]!=posK[1]){
            cout<<"YES";
            break;
        }else if(posW[2]-posK[2]==1 && posR[2]<=posW[2]+2 && posR[1]!=posK[1]){
            cout<<"YES";
            break;
        }else{
            cout<<"NO";
            break;
        }
    }
    
    return 0;
}