#include <iostream>
using namespace std;

int main(){
int n,a,xa,b,xb;
cin>>n>>a>>xa>>b>>xb;
int ca=0,cb=0,cont=0;
for (int i = 0;i<n;i++){
    ca+=1;
    cb+=1;
    if (ca==xa){
        a+=1;
        ca=0;
        };
    if (cb==xb){
        b+=1;
        cb=0;
        }
    if(a==b)
        cont+=1;


}
cout<<cont<<endl;




}