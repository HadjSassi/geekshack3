#include <bits/stdc++.h>
using namespace std;

int w[15],p[15];
int dp[15];
int main()
{
    int m , n;
    memset(dp,0,sizeof dp);
    cin >> m >> n;
    for(int i = 0;i<n;i++){
        cin >> w[i] >> p[i];
    }
    for(int i = 0;i<n;i++) {
        for (int j = 0; j <= m; j++) {
            if(j - w[i] >= 0){
                dp[j] = max(dp[j],dp[j - w[i]] + p[i]);
            }
        }
    }
    cout << dp[m];
    return 0;
}