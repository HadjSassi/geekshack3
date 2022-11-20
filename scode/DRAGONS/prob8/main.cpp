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
   int a[4];
   int z,b,c,d;
   cin>>z>>b>>c;
   if(!(cin>>d))
   // if (feof(stdin)) {
        cout << "NO";
    //}
    else{
        a[0]=z;a[1]=b;a[2]=c;a[3]=d;
        sort(a,a+4);
        cout<<a[0]*a[2];

    }
    return 0;
}
