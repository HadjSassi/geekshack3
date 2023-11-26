#include <iostream>
using namespace std;
int main(){
  int n,h,k,s1=0;
   cin>>n;
   int tab[6];
   int tab2[6];
   for(int i=0;i<6;i++){
       cin>>h>>k;
       tab[i]=h;
       tab2[i]=k;
       s1+=tab[i]+tab2[i];
   }
   cout<<(s1/2)+26;
   
   
         
       
    return 0;
}



