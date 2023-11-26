#include <stdio.h>
#include <stdlib.h>
#define Nmax 10000
int maxi(long int T[Nmax],int n){
    int max=T[0],d=0,i;
    for(i=1;i<n;i++){
        if(T[i]>max){
            max=T[i];
            d=i;
        }
    }
    return d;
}


int main()
{   int n,k,d,i;
    long int T[Nmax],e=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%ld",&T[i]);
    }
    while(k!=0){
         d=maxi(T,n);
         T[d]=0;
         k--;
    }
    for(i=0;i<n;i++){
        e+=T[i];
    }

    printf("%ld",e);
    return 0;
}
