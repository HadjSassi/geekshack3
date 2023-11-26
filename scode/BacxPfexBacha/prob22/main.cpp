#include <bits/stdc++.h>
using namespace std;
void Palindrome(string s, int n)
{
    unordered_map<char, int> cnt;
    string R = "";
    for (int i = 0; i < n; i++) {
        char a = s[i];
        cnt[a]++;
    }
    for (char i = 'a'; i <= 'z'; i++) {
        if (cnt[i] % 2 != 0)
            R += i;
    }

    int l = R.length();
    int j = 0;
    for (int i = l - 1; i >= l / 2; i--) {
        cnt[R[i]]--;
        R[i] = R[j];
        cnt[R[j]]++;
        j++;
    }
    string first, middle, second;

    for (char i = 'a'; i <= 'z'; i++) {
        if (cnt[i] != 0) {
            if (cnt[i] % 2 == 0) {
                int j = 0;
                while (j < cnt[i] / 2) {
                    first += i;
                    j++;
                }
            }
            else {
                int j = 0;
                while (j < (cnt[i] - 1) / 2) {
                    first += i;
                    j++;
                }

                middle += i;
            }
        }
    }

    second = first;
    reverse(second.begin(), second.end());
    string resultant = first + middle + second;
    cout << resultant << endl;
}
int main()
{
    string S;
    cin>>S;
    int n = S.length();
    Palindrome(S, n);
    return 0;
}

         