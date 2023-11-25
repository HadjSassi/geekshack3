#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    string s="NO";
    if(s2[2]==s3[2] || s2[1]==s3[1]){
        s="YES";
    }
    cout<<s;
    return 0;
}
