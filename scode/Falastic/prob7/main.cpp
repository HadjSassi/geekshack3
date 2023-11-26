#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> a,b;
    int n,z;cin>>n>>z;
    int A,B;
    while(n--){
        cin>>A>>B;
        a.push(-A);
        b.push(-B);
    }
    int cpt=0;
    while(z>0){
        if(-(a.top())<-(b.top())){
           cpt+=-(a.top());
           a.pop();
           z--;
           }
        else{
           cpt+=-(b.top());
           b.pop();
           z-=2;
        }
    }
    cout<<cpt;

    return 0;
}
   