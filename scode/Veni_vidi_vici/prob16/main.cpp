
#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
#define pdd pair<double,double>
#define int long long
#define pii pair<int,int>
vector<vector<pair<int,int>>> graph;
#define inf (int)1e9
int32_t main(){
    freopen("error1.txt", "w", stderr);
    int n,m,c;
    cin >> n >> m >> c;
    graph.resize(n+1);
    set<pair<int,pii>> edges;
    while(m--){
        int x,y,w;
        cin >> x >> y >> w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
        edges.insert({w,{x,y}});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> dis(n+1,inf);
    vector<bool> v(n+1,0);
    dis[c] = 0;
    pq.push({0,c});
    while(pq.size()){
        auto p = pq.top();
        pq.pop();
        int d = p.f, node = p.s;
        v[node] = 1;
        for(auto p1 : graph[node]){
            if(v[p1.f] || dis[p1.f] <= d + p1.s)continue;
            pq.push({d + p1.s, p1.f});
            dis[p1.f] = d + p1.s;
        }
    }
    int l;
    cin >> l;
    c = 0;
    for(int i = 0;i<n;i++){
        if(dis[i+1] == l)c++;
    }
    for(auto p : edges){
        int w = p.f, x = p.s.f, y = p.s.s;
        if(dis[x] >= l && dis[y] >= l)continue;
        if(dis[x] > dis[y]){
            swap(x,y);
        }
        if(dis[y] < l){
            if(2 * l  - dis[x] - dis[y] < w){
                c+=2;
            }
            if(2 * l - dis[x] - dis[y] == w){
                c++;
            }
            continue;
        }
        if(dis[y] == l){
            if(dis[x] + w <= l)continue;
            c++;
            continue;
        }
        if(dis[x] == l)continue;
        c++;
    }
    cout << c << endl;
}
