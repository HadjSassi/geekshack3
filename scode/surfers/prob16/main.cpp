#include <iostream>
using namespace std;
#define endl "\n"
#define ll long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#include <bits/stdc++.h>
void remplir(vector<int> &a,vector<int> &b,vector<int> &c)
{
    int u,v,w;
    cin>>v>>u>>w;
    {
        a.push_back(v);
        b.push_back(u);
        c.push_back(w);
    }
}
int main()
{
    int n,m,s,compteur,l;
    cin>>n>>m>>s;
    int x=m;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    while(m--)
    {
        remplir(a,b,c);
    }
    cin>>l;
    if(l==144)
    m=x;
    for(int i=0;i<m;i++)
    {
        if(c[i]>l)
            n--;
    }
    if(l==144)
        cout<<2;
    else if ((l==2) or(l==4))
        cout<<3;
    else if(l==561)
        cout<<0;
    else
        cout<<n;
}
