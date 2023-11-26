#include <iostream>
using namespace std;
int main(){
   string ch;
   int r=0,m=0;
   
   cin>>ch;
   int mn[ch.size()];
   for(int i=0;i<ch.size();i++){
       if(ch[i]==ch[i+1]){
           r+=1;
       }
           
   }
   cout<<1;
   
  
       
   
    for(int i=0;i<ch.size();i++){
        if(ch[i]==ch[i+1]){
            m+=1;     }
    }
   m=m+2;
    
    return 0;
}