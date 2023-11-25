#include<iostream>
using namespace std;
int main(){
    int x,y,vx,vy,k,h,l;
    cin>>l>>h>>x>>y>>vx>>vy>>k;
    int xf,yf;
    
    do{
    if(x==0){
        x=x+3*vx;
        y=y+vy;
        k--;
    }
    else if(y==h && x+vx<=l){
        x=vx+x;
        y=vy;
        k--;
    }else if(y==0 && x+vx>=l){
        x=l-vx;
        y=y+(h*vy)/2;
        k--;
    }else {
        x=x-vx;
        y=y+3*vy;
        k--;
    }
    }while(k==0);
   
    
    

     xf=x;
      yf=y;
     
    cout<<xf<<" "<<yf;
    
    
    
    return 0;
}