// C++ program to get lexicographically smallest
// palindrome string
#include <bits/stdc++.h>
using namespace std;

// Utility method to check str is possible palindrome
// after ignoring .
bool isPossiblePalindrome(string str)
{
	int n = str.length();
	for (int i=0; i<n/2; i++)
	{
		/* If both left and right character are not
		dot and they are not equal also, then it
		is not possible to make this string a
		palindrome */
		if (str[i] != '.' &&
			str[n-i-1] != '.' &&
			str[i] != str[n-i-1])
			return false;
	}

	return true;
}

// Returns lexicographically smallest palindrom
// string, if possible
string smallestPalindrome(string str)
{
	if (!isPossiblePalindrome(str))
		return "Not Possible";

	int n = str.length();

	// loop through character of string
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '.')
		{
			// if one of character is dot, replace dot
			// with other character
			if (str[n - i - 1] != '.')
				str[i] = str[n - i - 1];

			// if both character are dot, then replace
			// them with smallest character 'a'
			else
				str[i] = str[n - i - 1] = 'a';
		}
	}

	// return the result
	return str;
}

// Driver code to test above methods
int main()
{
 string s;
 cin >> s;
	cout << smallestPalindrome(s) << endl;
	return 0;
}
