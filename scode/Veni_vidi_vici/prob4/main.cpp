#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first

int a[200005],b[200005],state[200005];
void print(pair<int,int> p){
    cout << p.f << " " << p.s << endl;
}
int main(){
    int n,r;
    cin >> n >> r;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq1,pq2;
    for(int i = 0;i<n;i++){
        cin >> a[i] >> b[i];
        pq1.push({a[i],i});
        pq2.push({b[i],i});
    }
    long long res = 0;
    while(r > 1){
        if(pq1.size() == 1)break;
        auto p1 = pq1.top(), p3 = pq2.top();
        pq1.pop();
        if(state[p1.s] >= 2){
            continue;
        }
        auto p2 = pq1.top();
        pq1.pop();
        pq1.push(p1);
        if(state[p2.s] >= 2) {
            continue;
        }
        pq1.push(p2);
        if(state[p3.s] >= 1){
            pq2.pop();
            continue;
        }
        if(p2.f + p1.f < p3.f){
            pq1.pop();
            pq1.pop();
            res += p1.f + p2.f;
            if(state[p1.s] == 1){
                pq1.push({b[p1.s] - a[p1.s],p1.s});
            }
            if(state[p2.s] == 1){
                pq2.push({b[p2.s] - a[p2.s],p2.s});
            }
            state[p1.s]++;
            state[p2.s]++;
        }else{
            pq2.pop();
            state[p3.s] = 2;
            res += p3.f;
        }
        r -= 2;
    }
    if(r == 2){
        res += b[pq1.top().second];
    }else
    if(r){
        res += pq1.top().first;
    }
    cout << res << endl;
}

