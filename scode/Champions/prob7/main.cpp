#include <iostream>
using namespace std;
int main (){
    int n,z,a,b,suma=0,sumb=0,sum=0,k;
    
    cin>>n>>z;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        suma+=a;
        sumb+=b;
        sum=suma+sumb;
       }
       k=sum/n;
       if(k-(n*z)<=0){
           cout<<k+1;
       }
       else{
           cout<<k-(n*z);
       }
       return 0;
       }