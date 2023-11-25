// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count numbers in the range
// [l, r] having exactly one unset bit
int count_numbers(int L, int R)
{
	// Stores the required count
	int ans = 0;

	// Iterate over the range
	for (int n = L; n <= R; n++) {

		// Calculate number of bits
		int no_of_bits = log2(n) + 1;

		// Calculate number of set bits
		int no_of_set_bits
			= __builtin_popcount(n);

		// If count of unset bits is 1
		if (no_of_bits
				- no_of_set_bits
			== 1) {

			// Increment answer
			ans++;
		}
	}

	// Return the answer
	return ans;
}

// Driver Code
int main()
{
	int L = 4, R = 9;

	// Function Call
	cout << count_numbers(L, R);

	return 0;
}
