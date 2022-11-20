#include<stdio.h>
int main()
{
    
    int nb,t[100], i, j, x, y,a,z;
    scanf("%d\n",&nb);
    a=0;
    z=0;
    for (i=0; i<nb; i++)
    {
       scanf("%d %d\n", &x, &y);
       for (j=0;j<x;j++)
       {
           scanf("%d ",&t[j]);
       }
       j=0;
       while( j<= x-1)
       {
           if(t[j+1]<= t[j]+y)
           {
               a=a+(t[j+1]-t[j]);
               j++;
           }
           else if (t[j]+t[j+1]> y)
           {
               a=a+y;
               j++;
           }

       }
       a=a+y;
       z=z+a;


    }
    printf("%d",z);

}
    
       
    