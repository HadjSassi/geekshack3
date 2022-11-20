#include<stdio.h>

int main()

{
    int i,x,y,t[100],a=0;
    scanf("%d %d/n",&x,&y);
    for(i=0;i<x;i++)
    {
        scanf("%d ",&t[i]);
    }
    i=0;
    while(i<x-1)
    {
        if(t[i+1]<=t[i]+y)
        {
            a=a+(t[i+1]-t[i]);

        }
        else if (t[i]+t[i+1]>y)
        {
            a=a+y;

        }
        i=i+1;

    }
     a=a+y;
     printf("%d",a);

}