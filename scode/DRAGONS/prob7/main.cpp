#include <iostream>
#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
#define INPUT_ERROR
using namespace std;

/*int is_well_parenth(string ch,int n){
    int c=0;
    stack<char> s;
    for(int i=0;i<n;i++){
        if(ch[i]=='('){
            s.push(ch[i]);
            continue;}
        else{
            if(ch[i]==')'){
                if( !s.empty() && s.top()=='('){
                    s.pop();
                    continue;
                }
                else
                    c++;
            }
        }
    }
return 0;
}
*/
int main(){
string ch;
cin>>ch;
string s;
queue <int> p1,p2,m1,m2,a1,a2,c,dc,n1;
for (int i=0;i<ch.length();i++)
{
    if (ch[i]=='(')
        p1.push(i);
    if (ch[i]==')')
        p2.push(i);
    if (ch[i]=='[')
        m1.push(i);
    if (ch[i]==']')
        m2.push(i);
    if (ch[i]=='{')
        a1.push(i);
    if (ch[i]=='}')
        a2.push(i);
    if (ch[i]=='\'')
        c.push(i);
    if (ch[i]=='"')
        dc.push(i);
}
//if (p1.size()==0 ||.. )
s="";
for(int i=0;i<ch.length();i++)
{
    int v1,v2;
    if(p1.front()==i)
    {
        p1.pop();

    if(!p2.empty())
     {
        v2=p2.front();
        p2.pop();
        if(!p1.empty()&& !p2.empty() && i+1==(p1.front()))
        {
          int k,f;
          k=p1.front();
          f=p2.front();
          p1.pop();
          p2.pop();
          for (int j=i;j<=f;j++)
            s=s+ch[j];
        s=s+" ";
         for (int j=k;j<=v2;j++)
            s=s+ch[j];
        s=s+" ";
        } 
        else{
        for (int j=i;j<=v2;j++)
            s=s+ch[j];
        s=s+" ";
        }

    }

    }
    if(m1.front()==i)
    {
    if(!m2.empty())
     {
        v2=m2.front();
        m2.pop();
        for (int j=i;j<=v2;j++)
            s=s+ch[j];
        s=s+" ";

    }
    m1.pop();
    }
    if(a1.front()==i)
    {
    if(!a2.empty())
     {
        v2=a2.front();
        a2.pop();
        for (int j=i;j<=v2;j++)
            s=s+ch[j];
        s=s+" ";

    }
    a1.pop();
    }
if((!c.empty())&&(c.front())==i)

    {
        c.pop();
    if(!c.empty())
     {
        v2=c.front();
        c.pop();
        for (int j=i;j<=v2;j++)
            s=s+ch[j];
        s=s+" ";

    }
    
    }

if((!dc.empty())&&(dc.front())==i)
    {
        dc.pop();
    if(!dc.empty())
     {
        v2=dc.front();
        dc.pop();
        for (int j=i;j<=v2;j++)
            s=s+ch[j];
        s=s+" ";

    }
    dc.pop();
    }
}
if (s.length()==0)
    cout<<"SYNTAX_ERROR"<<endl;
else
{
    for (int j=0;j<s.length()-1;j++)
        cout<<s[j];
}












return 0;
}

