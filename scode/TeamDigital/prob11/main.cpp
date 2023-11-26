#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 int solve(int* health, int n)
{  for (int i = 2; i < n; ++i) {
      int  cugcd = gcd(cugcd, health[i]);
    }
    return cugcd ;
}
 int main()
{
    int health[] = { 4, 6, 8, 12 };
    int n = sizeof(health) / sizeof(health[0]);
    cout << solve(health, n);
 
    return 0;
}  