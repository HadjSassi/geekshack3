
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;



int main() {
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(auto &p : a)cin >> p;
    sort(a.begin(),a.end(),greater<long long>());
    long long sum = 0;
    for(int i = k;i<n;i++){
        sum += a[i];
    }
    cout << sum;
    return 0;
}

