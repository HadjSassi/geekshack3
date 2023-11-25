#include<stdio.h>

int bin0(long int k){
    int i=0;
    while (k/2)
    {
        if (!(k%2)) i++;
        k/=2;
        if (i>1) return 0;
    }
    if(!i) return 0;
    return 1;
    
}

void main(){
    long int min,max,i;
    int k=0;
    scanf("%ld %ld",&min,&max);
    for (i=min;i<=max;i++){
        k+=bin0(i);}
    printf("%d\n",k);
} 