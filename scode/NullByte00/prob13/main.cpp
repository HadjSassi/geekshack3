#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> numbers = { 12, 15, 18, 21, 24 };
    int ans =__gcd(numbers[0], numbers[1]);
    for (int i = 2; i < numbers.size(); i++)
    {
        ans = __gcd(ans, numbers[i]);
    }
    cout << "The GCD of the numbers in the vector is: " <<ans<<endl;
    return 0;
}