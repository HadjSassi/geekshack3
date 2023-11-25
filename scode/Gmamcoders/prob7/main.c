#include <stdio.h>

#define nmax  30000
int main()
{ int n,z,ind ,ai,bi,sum,t[nmax], t1[nmax],s=0,i,minai,minbi;
scanf("%d%d",&n,&z);
for (i=0;i<n;i++)
{scanf("%d%d",&ai,&bi);
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
 { minai=t[i] ;
 t[i]=300000;
 }


 if (t1[i]<minbi)
 { minbi=t1[i];
   t1[i]=300000;
    ind=i;
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
  t1[ind]=30000;
  minbi=t1[0];
 for(i=0;i<n;i++)
   if (t[i]<minbi)
 { minbi=t1[i];
   t1[i]=300000; }
 if (s<z)
 {sum+=minbi;
 s+=2;}
}


else if (n<z)
{sum+=minbi;
 s+=2;
  if((s-2==z)&&(minai+minbi<minbi) )
  {sum+=minbi;
   s+=2;}
 if (s<z)
 {sum+=minai;
 s++;}
}

 }
printf("%d",sum);

}




