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

