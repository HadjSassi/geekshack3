#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int get_pgcd(int a, int b)
{
    int pgcd = 0;

    while(1)
    {
        pgcd = a % b;
        if(pgcd == 0)
        {
            pgcd = b;
            break;
        }
        a = b;
        b = pgcd;
    }

    return pgcd;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int n,a,fpgcd,sum,sum1;
    cin>>n;
    vector<int> v(n),v1(n);
    for (int i=0;i<n;i++){
        cin>>a;
        v[i]=a;
    }
    v1[0]=v[0];
    fpgcd=v1[0];
    for (int i=1;i<n;i++){
        if (get_pgcd(v[i],fpgcd)>1){
            v1[i]=v[i];
            sum=v[i]+fpgcd+(i+1)*v[i];
        }
        else{
                v1[i]=0;

        }
    }

cout<<sum;
return 0;
}
