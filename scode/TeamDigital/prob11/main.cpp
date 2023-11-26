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
        currentgcd = gcd(currentgcd, health[i]);
    }
    return currentgcd;
}
 int main()
{
    int health[] = { 4, 6, 8, 12 };
    int n = sizeof(health) / sizeof(health[0]);
    cout << solve(health, n);
 
    return 0;
}