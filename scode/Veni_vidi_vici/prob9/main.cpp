#include <bits/stdc++.h>
using namespace std;

#define pdd pair<double,double>

int32_t main(){
    int n,m;
    cin >> n >> m;
    vector<pdd> a(n),b(m);
    for(int i = 0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 0;i<m;i++){
        cin >> b[i].first >> b[i].second;
    }
    double m1 = 0, m2 = 0;
    for(pdd &d : a)m1 = max(m1, d.first * d.first + d.second * d.second);
    for(pdd &d : b)m2 = max(m2, d.first * d.first + d.second * d.second);
    bool valid = 1;
    for(int i = 0;i<n;i++){
        double dis = a[i].first * a[i].first + a[i].second * a[i].second;
        if(dis <= m2){
            valid = 0;
        }
    }
    if(valid){
        cout << "YES" << endl;
        return 0;
    }
    valid = 1;
    for(int i = 0;i<m;i++){
        double dis = b[i].first * b[i].first + b[i].second * b[i].second;
        if(dis <= m1){
            valid = 0;
        }
    }
    if(valid){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}



  