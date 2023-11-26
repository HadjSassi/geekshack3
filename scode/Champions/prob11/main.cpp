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
   cout<<s/2;
    return 0;
}