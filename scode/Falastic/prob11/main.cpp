#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> a;
    long long n,k;cin>>n>>k;
    long long b;
    long long c=n;
    while(n--){
        cin>>b;
        a.push(b);
    }
    if(k>c){
        cout<<0;
        return 0;
    }
    long long cpt=0;
    while(k>0){
        a.pop();
        k--;
    }
    while (!a.empty()) {
         cpt+=a.top();
         a.pop();
    }
    cout<<cpt;
    return 0;
}
