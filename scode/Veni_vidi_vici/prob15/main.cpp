#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
#define pdd pair<double,double>


int main(){
    long long l,r;
    cin >> l >> r;
    int c = 0;
    for(long long i = 1;i<62;i++){
        long long n = (1ll << i) - 1;
        for(long long j = 0;j<i-1;j++){
            long long m = n ^ (1ll << j);
            if(m >= l && m <= r){
                c++;
            }
        }
    }
    cout << c << endl;
} 