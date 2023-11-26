#include <stdio.h>
#define nmax 500

int main()
{int max, n,h,i,sum=0,t[nmax],k;

scanf ("%d%d",&n,&k);
for (i=0;i<n;i++)
scanf("%d",&h);

while(k>0)
{
max=t[0];
for (i=0;i<n;i++)
if (t[i]>max)
   {max=t[i];
    t[i]=0;
    k--;}
}
for (i=0;i<n;i++)
if (t[i]!=0)
 sum+=t[i];

 printf("%d",sum);


}
 