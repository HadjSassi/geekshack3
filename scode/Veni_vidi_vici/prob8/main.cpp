#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;



int main() {
    int n;
    cin >> n;
    int cards = 0;
    vector<list<int>> a(n);
    for(int i = 0;i<n;i++){
        int m;
        cin >> m;
        a[i].resize(m);
        for(int &j : a[i])cin >> j;
        cards += m;
    }
    long long s1 = 0,s2 = 0;
    bool turn = 1;
    while(cards > 0){
        if(turn){
            int maxi = 0,idx = -1;
            for(int i = 0;i<n;i++){
                if(a[i].empty())continue;
                if(idx == -1){
                    idx = i;
                    maxi = *a[i].begin();
                    continue;
                }
                if(maxi > *a[i].begin()){
                    idx = i;
                    maxi = *a[i].begin();
                }
            }
            a[idx].erase(a[idx].begin());
            turn = 0;
            s1 += maxi;
        }
        else {
            int maxi = 0,idx = -1;
            for(int i = 0;i<n;i++){
                if(a[i].empty())continue;
                if(idx == -1){
                    idx = i;
                    maxi = *(--a[i].end());
                    continue;
                }
                if(maxi > *(--a[i].end())){
                    idx = i;
                    maxi = *(--a[i].end());
                }
            }
            s2 += maxi;
            a[idx].erase(--a[idx].end());
            turn = 1;
        }
        cards--;
    }
    cout << s1 << " " << s2 << endl;
    return 0;
}

  