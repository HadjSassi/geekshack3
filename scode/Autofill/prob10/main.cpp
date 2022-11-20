#include <bits/stdc++.h>

using namespace std;

bool notdigit(char c){
    return !(c >= '0' && c <= '9');
}
int main() {
    int nbu;
    int n,nb;
    int sum = 0;
    string nbuu;
    getline(cin,nbuu);
    stringstream ssss5(nbuu);
    ssss5 >> nbu;
    for(int u = 0; u< nbu ; u++) {
        string s1 , s2;
        getline(cin,s1);
        getline(cin,s2);
        stringstream ss1(s1),ss2(s2);
        ss1 >> nb >> n;
        int nbt[nb];
        for (int i = 0; i < nb; i++) {
            string x;
            ss2 >> x;
            if (!notdigit(x[0])) {
                stringstream ss3(x);
                int t;
                ss3 >> t;
                nbt[i] = t;
            } else {
                cout << "NO";
                return 0;
            }
        }
        int k = 0;
        for (int i = 0; i < nb - 1; i++) {
            if (nbt[i + 1] - nbt[i] < n) k += nbt[i + 1] - nbt[i];
            else k += n;
        }
        k += n;
        sum += k;
    }
    cout<<sum;
    return 0;
}