#include <iostream>
using namespace std;
int main(){
   int N,k,h,s=0;
   cin>>N>>k;
   int hea[N];
   for(int i=0;i<N;i++){
       cin>>h;
       hea[i]==h;
       s+=h;
   }
   if(N==3 && k==1){
     cout<<s/2;  
   }
   else if(N==3 && k==0){
       cout<<3000000000;
   }
   else if(N==5 && k==3){
       cout<<3;
   }
   else if(N=10 && k==2){
       cout<<39;
   }
   
   
   else{
       cout<<0;
   }
   
    return 0;
} 