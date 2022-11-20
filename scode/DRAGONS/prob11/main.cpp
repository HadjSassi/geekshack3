#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> input;
    string s;
    bool test=true;
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            if(!isdigit(s[i+1])){
                int a=s[i]-'0';
                input.push_back(a);
            }
            else
            {
                int a=s[i]-'0';
                int b=s[i+1]-'0';
                input.push_back(a*10+b);
                break;
            }
        }
        if(isalpha(s[i]))
            test=false;
    }
    if(test){
    int sum=0;
    for(int i=0;i<input.size();i++)
    {
        sum+=input[i];
    }
    int k=0;
    int num=sum;
    //cout<<num<<endl;
    while(num)
    {
        num=num/2;
        k++;
    }
    //cout<<k<<endl;
    //cout<<sum<<endl;
    int l=k;
    while(k)
    {
        //cout<<k<<endl;
        //cout<<j<<endl;
        int j=0;
        if(sum>>(k-1)&1)
            j = 1<<k-1;
        //cout<<j<<endl;
        string ch="";
        if(j==1)
            ch="take_position";
        else if(j==2)
            ch="run";
        else if(j==4)
            ch="need_backup";
        else if(j==8)
            ch="declare_your_position";
        if(k==l&&j)
            cout<<ch;
        else if(j)
            cout<<' '<<ch;
        k--;
    }
    }
    else
        cout<<"NOT_CLEAR"<<endl;
}
