//
// Created by CHAABANE IHEB on 28/11/2021.
//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    //cin.tie();
    //cin.ignore();
    vector<int>v;
    while(n--){
        cin>>s;
        int t=0;
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) {
                t += max(s[i], s[j]) - min(s[i], s[j]);
            }
                i++;
                j--;
        }
        //cout<<t<<endl;
        v.push_back(t);
    }
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1){
            cout<<v[i];
        }
        else
            cout<<v[i]<<endl;

    }

    return 0;
}

 