#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int hour,n;
    cin>>hour>>n;
    vector<int> profit(n),hours(n);
    vector<char> business(n);
    for(int i=0;i<n;i++)
    {
        int h,p;
        char b;
        cin>>b>>h>>p;
        business[i]=b;
        hours[i]=h;
        profit[i]=p;
    }
    int j;
    int tmp,tmh;
    char tmb;
    for(int i=1;i<n;i++)
    {
        j=i-1;
        tmp=profit[i];
        tmh=hours[i];
        tmb=business[i];
        while((tmh<hours[j]||(tmh==hours[j]&&tmp>=profit[j]))&&j>=0)
        {
            profit[j+1]=profit[j];
            hours[j+1]=hours[j];
            business[j+1]=business[j];
            j--;
        }
        profit[j+1]=tmp;
        hours[j+1]=tmh;
        business[j+1]=tmb;
    }
    int p=0,h=0;
    int maxprofit=0;
    vector<char> output;
    for(int i=0;i<n;i++)
    {
        vector<char> str;
        j=i+1;
        str.push_back(business[i]);
        p=profit[i];
        h=hours[i];
        while(j<n)
        {
            if(h+hours[j]<=hour)
            {
                h+=hours[j];
                p+=profit[j];
                str.push_back(business[j]);
                j++;
            }
            else
            {
                break;
            }
        }
        if(p>maxprofit){
            maxprofit=p;
            output=str;
        }
    }

    /*for(int i=0;i<n;i++)
    {
        cout<<business[i]<<' '<<hours[i]<<' '<<profit[i]<<endl;
    }*/
    sort(output.begin(),output.end());
    int s=output.size();
    for(int i=0;i<s;i++)
    {
        if(i==s-1)
            cout<<output[i]<<endl;
        else
            cout<<output[i]<<' ';
    }
    cout<<maxprofit<<endl;
    return 0;
}