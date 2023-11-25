#include<stdio.h>

int bin0(int k){
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
    int min,max,i,k=0;
    scanf("%d %d",&min,&max);
    for (i=min;i<=max;i++){

        k+=bin0(i);}
    printf("%d\n",k);
}