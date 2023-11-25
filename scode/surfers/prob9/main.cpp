#include <iostream>
using namespace std;
#define endl "\n"
#define ll long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#include <bits/stdc++.h>
int rayon(int n)
{
    int r=0;
    int x,y;
    while(n--)
    {
        cin>>x>>y;
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
        cin>>x>>y;
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
    cin>>n>>m;
    int R =rayon(n);
    check(R,m);
}
