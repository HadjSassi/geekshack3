#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,f,t,a;
    cin>>n>>f>>t>>a;
    int fuel = t;
    vector<int> godis(n),retdis(n),gocost(n),retcost(n);
    for(int i=0;i<n;i++)
    {
        cin>>godis[i]>>gocost[i]>>retdis[i]>>retcost[i];
    }
    int profit=0;
    for(int i=0;i<a;i++)
    {
        int nb,p;
        cin>>nb>>p;
        profit+=nb*p;
        cin>>nb>>p;
        profit+=nb*p;
    }
    int len=0;
    for(int i=0;i<n;i++)
    {
        len+=godis[i];
    }
    len+=retdis[0];
    vector<int> stations,costs;
    for(int i=0;i<n;i++)
    {
        stations.push_back(godis[i]);
        costs.push_back(gocost[i]);
    }
    stations.push_back(2*retdis[0]);
    costs.push_back(retcost[0]);
    for(int i=1;i<n;i++)
    {
        stations.push_back(retdis[i]);
        costs.push_back(retcost[i]);
    }
    /*for(int i=0;i<2*n+1;i++)
    {
        cout<<stations[i]<<' ';
    }*/
    int nb_sta=stations.size();
    //cout<<nb_sta<<endl;
    int p=1<<nb_sta;
    //cout<<p<<endl;
//    int curr_pos=0;
    int curr_dis;
    int cost=0,min_cost=10000;
    stations.push_back(godis[0]);
    for(int i=0;i<p;i++)
    {
        fuel=t;
        cost=0;
        curr_dis=stations[0];
        for(int j=0;j<nb_sta+1;j++)
        {

            if(j==nb_sta)
            {
                if(curr_dis>fuel)
                    cost=1000000;
            }
            else if(curr_dis<=fuel)
            {
                if(i>>j&1)
                {
                    fuel-=curr_dis;
                    curr_dis=stations[j+1];
                    cost+=costs[j]*(f-fuel);
                    fuel=f;

                }
                else
                    curr_dis+=stations[j+1];
            }
            else
            {
                cost=1000000;
                break;
            }
        }
        //cout<<i<<' '<<cost<<endl;
        if(min_cost>cost)
        {
            min_cost=cost;
        }
    }
    cout<<min_cost<<endl;
    cout<<profit<<endl;
    cout<<profit-min_cost<<endl;
}