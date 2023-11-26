#include<stdio.h>
int main()
{
int a,test=0,test1=0,l,h,x,y,vx,vy,k;
scanf("%d%d%d%d%d%d%d" ,&l,&h,&x,&y,&vx,&vy,&k);
a=k;
while(a>0)
{if((x==l)&&(y!=h) )
 {x=x-vy;
 y=y+vy;
 a--;
 test1==1;
 }
 else if (test1==1)
 {x=x-vy;
 y=y+vy;
 a--;}
 else if(x+vy==l)
  {x=x+vy;
  y=y+vy;
  a--;}


 else {
 if(test==0)
   y=h;
 else
 y=x;
 a--;
 }

 }
 printf("%d %d",x,y);


 }      