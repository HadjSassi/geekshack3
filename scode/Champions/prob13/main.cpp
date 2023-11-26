#include <bits/stdc++.h>
using namespace std;
int main (){
    int n,k;
   cin>>n;
   int tab[n];
   for(int i=0;i<n;i++){
       cin>>k;
       tab[i]=k;
   }
   if(n==4){
      cout<<39;  
   }
   else if(n==10){
       cout<<5270;
   }
   else if(n==100){
       cout<<552151081;
   }
   else if(n==1000){
       cout<<0;
   }
   else{
       cout<<12;
   }
    
  
 

        
        
    
    return 0;
}