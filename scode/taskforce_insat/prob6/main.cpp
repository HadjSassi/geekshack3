
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
  string s[N];
     int val[N];
    int wt[N] ;
int  n, W ; 
void printknapSack()
{
    vector<string>rs;
    int i, w;
    int K[n + 1][W + 1];
 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int res = K[n][W];
   int res1=res;
    w = W;
   for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;   
        else {
            rs.push_back(s[i-1]);
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
    for(int i = rs.size()-1 ; i>=0;i--)cout<<rs[i]<<(i!=0?' ':'\n');
     cout<< res1<<endl;
     return ;
}

int main()
{
   
    cin>>W ;  
    cin>>n ; 
  
    for(int i = 0 ; i<n ; i++){
        cin>>s[i]>>wt[i]>>val[i];
    }
     
    printknapSack();

    return 0;
}
 