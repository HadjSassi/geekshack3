#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int main(){
    int m,n,a,b,c,d;
cin>>n>>m;
map<int,int> m1,m2;
int max,calc;
cin>>a,b;
max=sqrt(pow(a,2)+pow(b,2));
for (int i=1;i<n;i++){
    cin>>a,b;
    m1[a]=b;
    calc=sqrt(pow(a,2)+pow(b,2));
    if(calc>max){
        max=calc;
    }
}
///cin>>c>>d;
for (int j=0;j<m;j++){
    cin>>c>>d;
    m1[a]=b;
    if (pow(m1[a],2)+pow(b,2)<pow(max,2)) {
        cout<<"NO";
        return 0;
    }
}
cout<<"YES";

return 0;
}