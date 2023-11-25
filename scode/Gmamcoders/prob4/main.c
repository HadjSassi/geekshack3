#include<stdio.h>

int main()
{
int a,test=0,l,h,x,y,vx,vy,k;
scanf("%d%d%d%d%d%d%d" ,&l,&h,&x,&y,&vx,&vy,&k);
a=k;


while(a!=0)
{if(x+vy==k)
 {x=x+vy;
 y=y+vy;

  }

 else {
 x=x+y;
 if(test==0)
   y=h;
 else
 y=0;
 test=1;
 a--;
 }

 }
 printf("%d %d",x,y);


 }