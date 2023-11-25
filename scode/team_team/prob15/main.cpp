#include <iostream>
using namespace std;

// function to convert decimal to binary
int decToBinary(int n)
{
    int c=0;
    // array to store binary number
    int m;

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        m= n % 2;
        if(m==0)
        {
            c++;
        }
        n = n / 2;
        i++;
    }

    return c;
}

// Driver program to test above function
int main()
{
    int a;
    int b;
    int c=0;
    cin >> a;
    cin >> b;
    for(int i=a;i<b+1;i++){
        if(decToBinary(i)==1)
            c++;
    }
    cout << c;
    return 0;
}
 