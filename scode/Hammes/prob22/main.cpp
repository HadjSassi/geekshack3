// C++ program to rearrange characters in a string
// so that no two adjacent characters are same.

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

struct Key {

	int freq; // store frequency of character
	char ch;

	// Function for priority_queue to store Key
	// according to freq
	bool operator<(const Key& k) const
	{
		return freq < k.freq;
	}
};

// Function to rearrange character of a string
// so that no char repeat twice
void rearrangeString(string str)
{
	int N = str.length();

	// Store frequencies of all characters in string
	int count[MAX_CHAR] = { 0 };
	for (int i = 0; i < N; i++)
		count[str[i] - 'a']++;

	// Insert all characters with their frequencies
	// into a priority_queue
	priority_queue<Key> pq;
	for (char c = 'a'; c <= 'z'; c++) {
		int val = c - 'a';
		if (count[val]) {
			pq.push(Key{ count[val], c });
		}
	}

	// 'str' that will store resultant value
	str = "";

	// work as the previous visited element
	// initial previous element be. ( '#' and
	// it's frequency '-1' )
	Key prev{ -1, '#' };

	// traverse queue
	while (!pq.empty()) {
		// pop top element from queue and add it
		// to string.
		Key k = pq.top();
		pq.pop();
		str = str + k.ch;

		// IF frequency of previous character is less
		// than zero that means it is useless, we
		// need not to push it
		if (prev.freq > 0)
			pq.push(prev);

		// Make current character as the previous 'char'
		// decrease frequency by 'one'
		(k.freq)--;
		prev = k;
	}

	// If length of the resultant string and original
	// string is not same then string is not valid
	if (N != str.length())
		cout << " Not possible " << endl;

	else // valid string
		cout << str << endl;
}
string str;
cin>>str;

	// Function call
rearrangeString(str);
	return 0;
 