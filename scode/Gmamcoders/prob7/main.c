#include <stdio.h>

#define nmax  30000
int main()
{ int n,z,inda,indb,minai1 ,ai,bi,sum,t[nmax], t1[nmax],s=0,i,minai,minbi;
scanf("%d%d",&n,&z);



for (i=0;i<n;i++)
{
scanf("%d%d",&ai,&bi);
 t[i]=ai;
 t1[i]=bi;
 }


minai=t[0];

minbi=t1[0];
sum=0;
while(s<z)
{


for (i=0;i<n;i++)
{
 if (t[i]<minai )
 {
  minai=t[i] ;
 t[i]=300000;
  inda=i;
 }

 if (t1[i]<minbi)
 { minbi=t1[i];
   t1[i]=300000;
    indb=i;
  }
 }


if(n>z)
  {

 sum+=minai;
 s++;
 if (s<z)
 {sum+=minbi;
 s+=2;}
}




else if  ((n<z)&&(z%n==0))
{sum+=minbi;
 s+=2;
  t1[indb]=30000;
  minbi=t1[0];
 for(i=0;i<n;i++)
   if (t[i]<minbi)
 { minbi=t1[i];
   t1[i]=300000; }
 if (s<z)
 {sum+=minbi;
 s+=2;}
}

else if(n<z)
{
if((s-2==z)&&(minai+minai1<minbi)){sum+=minbi;s+=2;}

if(minai>minbi)
{
sum+=minbi;
 s+=2;
 t1[indb]=30000;
 minbi=t1[0];
 for(i=0;i<n;i++)
  if (t1[i]<minbi)
 {minbi=t1[i];
   t1[i]=300000;
   indb=i;}
  }

else
{sum+=minai;
 s++;
 t[inda]=30000;
 minai=t[0];
 for(i=0;i<n;i++)
 if (t[i]<minai)
 { minai=t[i];
   t[i]=300000;
   inda=i;}
}

 } }
printf("%d",sum);
}




 