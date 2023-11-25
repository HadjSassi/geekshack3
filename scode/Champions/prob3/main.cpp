#include<iostream>
#include<algorithm>
#include <string>
using namespace std;

int main(){
    int n,z,a=0,b=0;
    char i;
  string s,s1="chak",s2="chouka";
 
getline(cin,s);
n=s.find(s1,0);
while(n!=string::npos){
    a++;
    n=s.find(s1,n+1);
}
//cout<<a<<endl;
z=s.find(s2,0);
while(z!=string::npos){
    b++;
    z=s.find(s2,z+1);
}
//cout<<b;
if (a<b){
    cout<<a*2;
}else if (a>b){
    cout<<b*2;
}else{
    cout<<a*2;
}

   
    return 0;
}
         
   