#include<dos.h>
#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
void main()
 {

 int d=DETECT,m;
 initgraph(&d,&m,"C:\\TC\\BGI");
 float x=1,y,j=0.5,count=0.1,i;
 setcolor(01);
 for(int k=0;k<7;k++)
 {
  for(i=90;i<270;i+=10)
  {
   y=cos(i*3.14/180)/j;
   if(y>0)
    y=-y;
   x+=5;
   setfillstyle(1,01);
   circle(x,y*100+200,15);
   floodfill(x,y*100+200,01);
   line(0,215,800,215);
   delay(50);
   clrscr();
  }
 j+=count;
 count+=0.1;
 }
 getch();

 }

  