#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int x = 7;
    
    cout << "Value of x is " << x << endl;
    
    cout << "Value of x is now" << x++ << endl;

    cout << "Value of x is now " << x << endl;

    cout << "Value of x is now " << ++x << endl;

    cout << "Value of x is now " << x << endl;

    return 0;
}