#include <iostream>
#include <cmath>
int rayon(int n)
{
    int r=0;
    int x,y;
    while(n--)
    {
        std::cin>>x>>y;
        if(sqrt(x*x+y*y)>r)
            r=sqrt(x*x+y*y);
    }
    return r;
}
void check(int R,int m)
{
    int x,y;
    while(m--)
    {
        std::cin>>x>>y;
        if(sqrt(x*x+y*y)<=R)
        {
            printf("NO");
            return ;
        }
    }
    printf("YES");
}
int main()
{
    int m,n;
    std::cin>>n>>m;
    int R =rayon(n);
    check(R,m);
}
