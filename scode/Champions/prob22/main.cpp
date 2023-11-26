#include <bits/stdc++.h>
using namespace std;
int main (){
    string ch;
    cin>>ch;
    string ch1;
     string ch2;
      string ch3;
    
    for(int i=0;i<ch.size()/2;i++){
        ch1+=ch[i];
    }
    for(int j=ch.size()/2;j<ch.size();j++){
           ch2+=ch[j];
            
        }
  ch2[1]='a';
  ch1[1]='q';
  ch=ch1+ch2;
  cout<<ch;
        
        
        

        
        
        
    
    return 0;
}