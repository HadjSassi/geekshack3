#include<stdio.h>

int main(){
     int n,m,i,j,nb,l;
    int T[n][m];
    n=2;
    m=3;
    i=0;
    j=0;
    int T1[100];
    do{
        l=0;nb=0;
        if (T[i][j]=1){
            l=100;
            if (T[i+1][j]==1){
                l+=100;
                i+=1;
            else if (T[i][j+1]==1) {
                l+=100;
                j+=1;
            }
            T1[nb]=l;
            nb+=1;
        }
    }while((i<n-1)||(j<m-1));
    for(i=0;i<nb-1;i++){
        printf("%d",T1[i]);
    }
    return 0;
} 