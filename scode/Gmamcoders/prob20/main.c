#include <stdio.h>
#define nmax 500

int main()
{int n,m,t[nmax][nmax],i,j;
scanf ("%d%d",&n,&m);
for(i=0;i<n;i++)
for(j=0;j<n;j++)
 scanf("%d",&t[i][j]);


for(i=0;i<n;i++)
for(j=0;j<n;j++)
 {if ((t[i][j]!=0)&&(t[i][j]==t[i+1][j+1]==t[i+2][j+2]==t[i+3][j+3])  )
   {  if (t[i][j]==1)
    {printf("1");
    return 0;}
    else if(t[i][j]==2)
    {printf("2");
     return 0;}
     }
if ((t[i][j]!=0)&&(t[i][j]==t[i-1][j-1]==t[i-2][j-2]==t[i-3][j-3])  )
 {      if (t[i][j]==1)
    {printf("1");
    return 0;}
    else  if(t[i][j]==2)
    {printf("2");
     return 0;}
  }



if ((t[i][j]!=0)&&(t[i][j]==t[i][j+1]==t[i][j+2]==t[i][j+3]))
   {       if (t[i][j]==1)
    {printf("1");
    return 0;}
    else  if(t[i][j]==2)
    {printf("2");
     return 0;}
    }
 if ((t[i][j]!=0)&&(t[i][j]==t[i+1][j]==t[i+2][j]==t[i+3][j]  ))
  {       if (t[i][j]==1)
    {printf("1");
    return 0;}
    else  if(t[i][j]==2)
    {printf("2");
     return 0;}
  }
     }
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
if ((t[i][j]!=0)&&(t[i][j]==t[i][j+1]==t[i][j+2]==t[i][j+3]) ||((t[i]!=0)&&(t[i][j]==t[i][j+1] ==t[i][j+2])&&(t[i][j+3]==0)))
  {  if (t[i][j]==1)
    {printf("1");
    return 0;}
    else  if(t[i][j]==2)
    {printf("2");
     return 0;}
   }
if ((t[i][j]!=0)&&(t[i][j]==t[i+1][j]==t[i+2][j]==t[i+3][j]  )||((t[i]!=0)&&(t[i][j]==t[i+1][j] ==t[i+2][j])&&(t[i+3][j]==0)))
 {
   if (t[i][j]==1)
    {printf("1");
    return 0;}
    else  if(t[i][j]==2)
    {printf("2");
     return 0;}
  }
if ((t[i][j]!=0)&&(t[i][j]==t[i+1][j+1]==t[i+2][j+2]==t[i+3][j+3])||((t[i]!=0)&&(t[i][j]==t[i+1][j+1] ==t[i+2][j+2])&&(t[i+3][j+3]==0)))
   {
     if (t[i][j]==1)
    {printf("1");
    return 0;}
    else  if(t[i][j]==2)
    {printf("2");
     return 0;}
    }
}
printf("0");
return 0;

} 