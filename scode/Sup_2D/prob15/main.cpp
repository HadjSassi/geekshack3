#include<bits/stdc++.h>

using namespace std;
string decToBinary(int n)
{
    int binaryNum[32];

    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    string res;
    for (int j = i - 1; j >= 0; j--){
        res+=to_string(binaryNum[j]) ;
    }
        
    return res;    
}
int main()
{
    int a,b;
    cin>>a>>b;
    int out=0;

    for (int i=a; i<=b; i++)
    {
        string year_bin=decToBinary(i);
        if (count( year_bin.begin(),  year_bin.end(), '0')==1)
          {
             out ++;
          }
    }
    cout<< out;
    return 0;
}