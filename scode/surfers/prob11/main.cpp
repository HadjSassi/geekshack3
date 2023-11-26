#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    long n,k,x,sum;
    sum=0;
    std::cin>>n>>k;
    std::vector<int> v;
    if(k>=n)
        std::cout<<0;
    else
    {
        for(int i=0;i<n;i++)
        {
            std::cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for(int j=0;j<n-k;j++)
        {
            sum+=v[j];
        }
        std::cout<<sum;
    }
}
