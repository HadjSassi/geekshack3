#include <iostream>
using namespace std;
#define endl "\n"
#define ll long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#include <bits/stdc++.h>
int checkpal(string s)
{
    int n=s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
            return 0;
    }
    return 1;
}
string swapp(int i,int j,string s)
{
    char a=s[i];
    s[i]=s[j];
    s[j]=a;
    return s;
}
int check(string s)
{
    int n=s.length();
    int countt=0;
    int howmany=0;
    char c;
    for(int i=0;i<s.length();i++)
    {
     int compteur= std::count(begin(s),end(s),s[i]);
        if(((compteur)%2!=0)and(s[i]!=c))
         {
             countt++;
             c=s[i];
         }
        if(countt>1)
            return -1;
    }
    while(!(checkpal(s)))
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=s[n-1-i])
            {
                howmany+=(n-i-1)-((s.substr(i+1,s.length()-2*i)).find(s[i]))-i-1;
                s=swapp(n-1-i,s.substr(i+1,s.length()-2*i).find(s[i])+i+1,s);
                if(checkpal(s))
                    return howmany;
            }
        }

    }
    return howmany;
}
int main()
{
    string s;
    cin>>s;
    cout<<check(s);
}