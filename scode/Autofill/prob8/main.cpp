#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
typedef vector<pair<int,int>> vii;
bool notdigit(string s){

    for(char ca : s) {
        if (!(ca >= '0' && ca <= '9'))return 1;
    }
    return 0;
}
int main() {
    string ca,cb,cx,cy;
    if(!(cin >> ca >> cb >> cx >> cy)){
        cout << "NO";
        return 0;
    };
    if(notdigit(ca + cb +cx + cy)){
        cout << "NO";
        return 0;
    }
   int a ,b;
   int x , y;
    stringstream  geek(ca+ " " +cb + " "+cx+" " + cy);
    geek >> a >> b >> x >> y;
    vector<int> ar;
    ar.push_back(a);
    ar.push_back(b);
    ar.push_back(x);
    ar.push_back(y);
    sort(ar.begin(),ar.end());
    cout << ar[0] * ar[2];
}
