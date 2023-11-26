#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <utility>
using namespace std;


int main()
{
    long n;
    long z;
    long a;
    long b;
    int c,d;
    vector <long> v1;
    vector <long> v2;
    vector <pair<long,long>> m;
    std::cin >>n;
    std::cin >> z;
    for (int i=0;i<n;i++)
    {
        std::cin >> a;
        std::cin >> b;
        v1.push_back(a);
        v2.push_back(b);
    }
    c=0;d=0;
    for (int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
        {
            if((i+2*j)==z)
            {
               m.push_back({i,j});
            }
            if((i+2*j)>z)
                break;
        }
    }
    for(auto x:m)
    {
        std::cout<< x.first <<" " <<x.second <<std::endl;
        for(int i=0;i<x.first;i++)
        {

        }
        for(int i=0;i<x.second;i++)
        {

        }

    }

    return 0;
}
