#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,t;

    //int m='a';
    //cout<<m<<endl;
    bool test=true;
    int users;
    int time=0;
    cin>>users;
    for(int u=0;u<users;u++){
        cin>>n;
        if(!cin){
            cout<<"NO"<<endl;
            exit(1);
        }
        cin>>t;
         if(!cin){
            cout<<"NO"<<endl;
            exit(1);
        }

        vector<int> push(n);
        for(int i=0;i<n;i++)
        {
            cin>>push[i];
            if(!cin){
                cout<<"NO"<<endl;
                exit(1);
            }
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
        time+=total_time;
    }
    if(test)
        cout<<time<<endl;
    else
        cout<<"NO"<<endl;
}