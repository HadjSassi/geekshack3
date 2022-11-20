//
// Created by CHAABANE IHEB on 27/11/2021.
//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int b,n,p,e;
    vector<pair<int,int>>v;
    vector<int> ans;
    cin>>b;
    cin>>n;
    bool tst=false;
    while(n--){
        cin>>p>>e;
        v.push_back(make_pair(p,e));
    }
    for(int i=0;i<v.size()-1;i++) {
        if (v[i].first > b) {
            tst = true;
        } else {
            for (int j = i + 1; j < v.size(); j++) {
                if (2 * v[i].first <= b)
                    ans.push_back(2 * v[i].second);
                if (2 * v[i].first + v[j].first <= b)
                    ans.push_back(2 * v[i].second + v[j].second);
                if (2 * v[i].first + 2 * v[j].first <= b)
                    ans.push_back(2 * v[i].second + 2 * v[j].second);
                if (v[i].first <= b) {
                    ans.push_back(v[i].second);
                }
                if (v[i].first + v[j].first <= b)
                    ans.push_back(v[i].second + v[j].second);
                if (v[i].first + 2 * v[j].first <= b)
                    ans.push_back(v[i].second + 2 * v[j].second);
            }

        }
    }
    if(tst==true){
        cout<<v[v.size()-1].second;
        return 0;
    }
    sort(ans.begin(),ans.end());
    cout<<ans[ans.size()-1];




    return 0;
}
