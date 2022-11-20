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
    cin >> ca >> cb >> cx >> cy;
    if(notdigit(ca + cb +cx + cy)){
        cout << "INPUT_ERROR";
        return 0;
    }
   int a ,b;
   int x , y;
    stringstream  geek(ca+ " " +cb + " "+cx+" " + cy);
    geek >> a >> b >> x >> y;
   int c = (a-1) / (x+1) *((b-1) / (x+1));
   if(y <= c)cout << 4 * y;
   else {
       cout << c * 4  + (y-c) * 2;
   }
}
