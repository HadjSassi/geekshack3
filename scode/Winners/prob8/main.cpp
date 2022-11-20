#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if  (!(isdigit(a)) || (!(isdigit(b)) || (!(isdigit(c)) || (!(isdigit(d))
    {
        cout<<"NO"<<endl;
    }
    else
    {
    vector <int> p;
    p.push_back(a);
    p.push_back(b);
    p.push_back(c);
    p.push_back(d);
    sort(p.begin(),p.end());
    cout<<p[0]*p[2]<<endl;
        
    }
    
    
    return 0;
}