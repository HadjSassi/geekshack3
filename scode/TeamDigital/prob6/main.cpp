#include <bits/stdc++.h>
using namespace std;
string encrypt(string s, int l)
{
	string ans = "";
	if (l % 2) {
		int cnt = 0;
		int indl = 0, indr = l - 1;
		while (ans.size() != l) {
			if (cnt % 2 == 0)
				ans += s[indl++];
			else
				ans += s[indr--];

			cnt++;
		}
	}
	else {
		int cnt = 0;
		int indl = 0, indr = l - 1;
		while (ans.size() != l) {
			if (cnt % 2 == 0)
				ans += s[indr--];
			else
				ans += s[indl++];

			cnt++;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main()
{
	string s = "egekstisne";
	int l = s.length();
	cout << encrypt(s, l);
	return 0;
}
 