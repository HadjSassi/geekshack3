#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,t;
    cin>>n>>t;
    vector<int> push(n);
    for(int i=0;i<n;i++)
    {
        cin>>push[i];
    }
    int total_time=0;
    for(int i=1;i<n;i++)
    {
        if(push[i]-push[i-1]<t)
            total_time+=push[i]-push[i-1];
        else
            total_time+=t;
    }
    total_time+=t;
    cout<<total_time<<endl;
}