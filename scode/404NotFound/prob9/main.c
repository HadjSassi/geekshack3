#include<stdio.h>

int main(){
   int matrice[2][4] = {{0}};
   int i,j;
   for(i=0;i<2;i++){
       for(j=0;j<4;j++){
           scanf("%d",&matrice[i][j]);
       }
   }
    
printf("%d",(matrice[0][0]*matrice[0][1])-matrice[1][2]);
 
 
    return 0;
} 