#include<stdio.h>
#define nmax 10
int main(){
    int M[nmax][nmax];int i,j,n,m,nb;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
        scanf("%d",&M[i][j]);
    }
     for(i=0;i<n;i++){
         for(j=0;j<m-1;j++)
          if (M[i][j]==M[i][j+1]==M[i][j+3]==1 &&
          (M[i+1][j+2]==1 ||M[i-1][j+2]==1))
          
            printf("1");
            else if(M[i][j]==M[i][j+1]==M[i][j+3]==2 &&
              (M[i+1][j+2]==2 ||M[i-1][j+2]==2))
               printf("2");}
       
    return 0;
} 