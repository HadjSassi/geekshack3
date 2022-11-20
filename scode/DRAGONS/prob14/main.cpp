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
    int l,w;
    char t_size,nb_t;
    cin>>l>>w>>t_size>>nb_t;
    if(t_size>='a' ||nb_t>'a'){
        cout<<"INPUT_ERROR";
        exit(0);
    }
    int t_size0=t_size -'0',nb_t0=nb_t-'0';
    if(nb_t0==0 || nb_t0==1)
        cout<<nb_t0*t_size0;
    else {
        int t = l * w - (t_size0+1 ) * (t_size0+1) * nb_t0;
        if (t >= 0)
            cout << nb_t0 * t_size0;
        else
            cout << (nb_t0 - 1) * t_size0;
    }
    return 0;
}
      