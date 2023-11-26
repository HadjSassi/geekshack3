#include <iostream>
using namespace std;
int main(){
  int n,A,B,xa,xb;
   cin>>n>>A>>xa>>B>>xb;
   if(A>B && xa>xb){
       cout<<B+xb;
   }else if (A==B && xa>xb){
       cout<<xb;
   
   }else if(A>B && xb==xa){
       cout<<0;
   }else if (A<B && xa<xb){
       cout<<0;
   }else if (A==B &&xa==xb){
       cout<<n;
   }

   
         
       
    return 0;
}    