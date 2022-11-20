#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,a,f,t;
    string ans;
    while(cin >> n >> f >> t >> a){
        vector<pair<int,int>> going;
        vector<pair<int,int>> returning;
    
        int ma = 0, mi = t;
        for(int i = 0; i<n; ++i){
            int x,w,y,z;
            cin >> x >> w >> y >> z;
            going.push_back({x,w});
            returning.push_back({y,z});
            
        }
        going.push_back({returning[0].first,0});
        for(int i = 0; i < n; ++i){
            going.push_back(returning[i]);
        }
        going.push_back({going[0].first,0});
        for(int i = 0; i<a; ++i){
            int x,w,y,z;
            cin >> x >> w >> y >> z;
            ma += x*w + y*z;
        }
        mi = (int)(1e9);
        int fuel1;
        for(int i = 0; i<(1 << (2*n+2)); ++i){
            int cnt = 0;
            int fuel = t;
            bool com = true;

            int ab = 0;
            for(int j = 0; j<2*n+2; ++j){
                fuel -= going[j].first;
                if(fuel < 0){
                    com = false;
                    break;
                }
                if(i & (1 << j)){
                    if(going[j].second){
                        cnt += (f-fuel)*going[j].second;
                        fuel = f;
                    }

                }
            }
            if(com){
                fuel1 = fuel;
                mi = min(mi,cnt);
            }
                
        }
        cout << mi << '\n';
        cout << ma << '\n';
        cout << ma - mi << '\n';



        return;
    }
    cout << "NO";
}

int main(){
    solve();
} 