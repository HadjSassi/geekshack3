#include <iostream>
using namespace std;
int main(){
   int r,c,x,r1=0,y=0;
   cin>>r>>c;
   int grid[r][c];
   for(int i=0;i<r;i++){
       for(int j=0;j<c;j++){
           cin>>x;
           if(x==1){
               r1+=1;
           }if(r==2){
               y+=1;
           }
           grid[i][j]=x;
       }
   }
    for(int i=0;i<c;i++){
       for(int j=0;j<r;j++){
           if (grid[j][i]==grid[j+1][i]==grid[j+2][i]==grid[j+3][i]==1){
               if(r1<y){
               cout<<1;
               break;
               }
           }
               else{
                   if(grid[j][i]==grid[j+1][i]==grid[j+2][i]==grid[j+3][i]==2){
                       
               
               
                   }
          
       }
       
    }
    cout<<2;
           break;
       for(int i=0;i<r;i++){
       for(int j=0;j<c;j++){
           if (grid[j][i]==grid[j][i+1]==grid[j][i+2]==grid[i+3][j]==1){
               if(r1<y){
               cout<<1;
               break;
           }else{
               
            if(grid[j][i]==grid[j][i+1]==grid[j][i+2]==grid[i+3][j]==2){
               
               
            }
           
       }
       
       }
       }
       
       }
    }
        for(int i=0;i<r;i++){
       for(int j=0;j<c;j++){
           if (grid[j][i]==grid[j+1][i+1]==grid[j+2][i+2]==grid[i+3][j+3]==1){
               if(r1<y){
               cout<< 1;
               break;
           }
           else{
               if(grid[j][i]==grid[j+1][i+1]==grid[j+2][i+2]==grid[i+3][j+3]==2){
               
               
               
               }
       
       }
       
         }
         
       }
       
         }
         
       
    return 0;
}