#include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int n=s.length();
    map<char,int> m;
    for(auto i:s)
    {
        m[i]++;
    }
    int cnt=0;
    for(auto i=m.begin();i!=m.end();i++)
    {
        if(i->second%2)
        {
            cnt++;
        }
    }
    if(n%2&&cnt==1){return true;}
    if(!(n%2)&&cnt==0){return true;}
    return false;
}

int main()
{
    string a;
    cin>>a;

        string s;s=a;
        int n=s.length();
        //first check if
        int cnt=0;
        bool ini=false;
        if(n%2){ini=true;}
        if(check(s))
        {
            for(int i=0;i<n/2;i++)
            {
                bool fl=false;
                int j=0;
                for(j=n-1-i;j>i;j--)
                {

                    if(s[j]==s[i])
                    {
                        fl=true;
                        for(int k=j;k<n-1-i;k++)
                        {
                            swap(s[k],s[k+1]);
                            cnt++;
//                            cout<<cnt<<endl<<flush;
                        }
//                        cout<<" "<<i<<" "<<cnt<<endl<<flush;
                        break;
                    }
                }
                if(!fl&&ini)
                {
                    for(int k=i;k<n/2;k++)
                    {
                        swap(s[k],s[k+1]);
                        cnt++;

                    }
//                    cout<<cnt<<" "<<i<<" "<<endl<<flush;
                }
            }
            cout<<cnt<<endl;
        }
        else{
            cout<<-1<<endl;
        }


}
