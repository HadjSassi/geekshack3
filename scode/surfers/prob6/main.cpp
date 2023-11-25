#include <iostream>
using namespace std;
#define endl "\n"
#define ll long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define pb push_back

const int MOD = 1000000007;
const int MAX = 1000005;

int SetBit (int n, int x) { return n | (1 << x); }
int ClearBit (int n, int x) { return n & ~(1 << x); }
int ToggleBit (int n, int x) { return n ^ (1 << x); }
bool CheckBit (int n, int x) { return (bool)(n & (1 << x)); }

void main ()
{
    /*
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    */

    int n,i,j,h,k,len;
    string str;

    while (sf ("%d",&n) != EOF)
    {
        cin >> str;

        vector <int> v;

        for (i=1; i*i<=n; i++)
        {
            if (n % i == 0)
            {
                v.pb(i);

                if (i * i != n)
                    v.pb(n/i);
            }
        }

        sort (v.begin(),v.end());
        len = v.size();

        for (i=0; i<len; i++)
        {
            k = v[i];
            h = v[i]/2;

            for (j=0; j<h; j++)
                swap (str[j],str[k-1-j]);
        }

        cout<<str;
    }
}

