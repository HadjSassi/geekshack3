#include<stdio.h>


int max2entiers(int a,int b)
    {
        int max;
        if ( a>b )
        {
            max=a;
        }
        else max =b;
        return (max);
    }
int min2entiers(int a, int b)
{
    int min;
    if ( a<b )
    {
            min=a;
    }
    else min =b;
    return (min);
}
int main()
{

    int a,b,c,d,max1,max2, min1, min2, minmax, minmin, s;
    do
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if ( (a>= 'a' && a<='z') ||  (a>= 'A' && a<='Z') || (b>= 'a' && b<='z') ||  (b>= 'A' && b<='Z') || (c>= 'a' && c<='z') ||  (c>= 'A' && c<='Z')|| (d>= 'a' && d<='z') ||  (d>= 'A' && d<='Z'))
        {
            printf("%s","NO");
        }

    }
    while( (a==0) || (b==0) ||(c==0)||(d==0) );


    max1= max2entiers(a,b);
    max2= max2entiers(c,d);
    min1=min2entiers(a,b);
    min2=min2entiers(c,d);
    minmax=min2entiers(max1,max2);
    minmin=min2entiers(min1, min2);

    s=minmax*minmin;
    printf("%d",s);

}
