#include<bits/stdc++.h>
using  namespace  std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n+3];
        for(int i=0;i<n;i++)cin>>ar[i];
        vector<int>v;
        int i=0;
        int j=n-1;
        while(i<j)
        {
            v.push_back(ar[i]);
            v.push_back(ar[j]);
            i++;
            j--;
        }
        if(n%2==1)v.push_back(ar[i]);
        for(int i=0;i<n;i++)cout<<v[i]<<" ";
        cout<<endl;
 
    }
    return 0;
}