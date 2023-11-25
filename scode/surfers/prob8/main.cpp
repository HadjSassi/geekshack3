#include <iostream>
using namespace std;
#define endl "\n"
#define ll long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#include <bits/stdc++.h>
void solve(int &bachka,int &mabrouk,int &m)
{
    int s,x,i;
    cin>>s;
    vector<int> V;
    for(i=0;i<s;i++)
    {
        cin>>x;
        V.push_back(x);
    }
    for(int j=0;j<s/2;j++)
        {
            bachka+=V[j];
            mabrouk+=V[s-j-1];
        }
    if((m%2==0)and(s%2!=0))
    {

        bachka+=V[s/2];
    }
    else if ((m%2!=0)and(s%2!=0))
    {
       mabrouk+=V[s/2];
    }
    m+=s;
}
int main()
{
    int n,bachka,mabrouk,i;
    cin>>n;
    i=0;
    bachka=0;
    mabrouk=0;
    while(n--)
    {
        solve(bachka,mabrouk,i);
    }
    cout<<bachka<<" "<<mabrouk;
}
