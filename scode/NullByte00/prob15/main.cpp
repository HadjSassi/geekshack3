#include<iostream>

using namespace std;
bool count_zeros(int a){
        int zeros = 0;
        while(a!=0 and zeros<=2){
            if (a%2 == 0)
                zeros+=1;
            a = a >> 1;
        }
        return zeros == 1;
    }
int main(){

    int a, b;
    cin >> a;
    cin >> b;

    int count = 0;

    for(int i=a; i<=b; i++){
        if(count_zeros(i))
            count++;
    }
    cout << count << endl;
    return 0;
} 