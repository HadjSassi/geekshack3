#include<iostream>

using namespace std;

int main(){
    int N,F,T,A;
    cin>>N>>F>>T>>A;
    for(int i=0;i<N;i++)
    {
       int D1,C1,D2,C2;
       cin>>D1>>C1>>D2>>C2;
       int x=0
       if (i==0){
           x=(F-(D1-T))*C1+D2*C2;
       }
       else if (i==N-1){
           x=x+(F-(F-(D1+D2)))*C2+D1*C1;
       }
       else
       {
           x=x+D1*C1+D2*C2;
       }
    
    }
    int y=0;
    for(int i=0;i<A;i++)
    {
        int NBA,PA,NBR,PR;
        cin>>NBA>>PA>>NBR>>PR;
        y=y+NBA*PA+NBR*PR;
    }
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<y-x<<endl;
    
    return 0;
} 