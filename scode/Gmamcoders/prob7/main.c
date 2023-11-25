#include <stdio.h>

#define nmax  30000
int main()
{ int n,z ,ai,bi,sum,t[nmax], t1[nmax],s=0,i,minai,minbi;
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

  } }
 sum+=minai;
 s++;
 if (s<z)
 {sum+=minbi;
 s+=2;}
}


printf("%d",sum);

}



