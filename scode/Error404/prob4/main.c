#include <stdio.h>
#include <stdlib.h>

void bounce(int l,int h,int *x ,int *y,int vx,int vy){
    if(*y==0 || *y==h){
        *x+=vx;
        *y-=vy;
        while(*y!=h && *y!=0 && *x!=0 && *x!=l){
            *x+=vx;
            *y-=vy;
        }
        vy=-vy;
    }
    if(*x==0 || *x==l){
        *x-=vx;
        *y+=vy;
        while(*y!=h && *y!=0 && *x!=0 && *x!=l){
            *x-=vx;
            *y+=vy;
        }
        vx=-vx;
    }

}


int main()
{   int l,h,x,y,vx,vy,k;
    scanf("%d %d %d %d %d %d %d",&l,&h,&x,&y,&vx,&vy,&k);
    x+=vx;
    y+=vy;
    while(k!=0){
        bounce(l,h,&x,&y,vx,vy);
        k-=0;
    }
    printf("%d %d ",x,y);


    return 0;
}
