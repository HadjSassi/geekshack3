// C++ program for above approach
#include <iostream>
using namespace std;

// Function to return minimum
// Element between two values
int min(int x, int y) 
{ 
return (x < y) ? x : y; 
}

// Utility function for calculating
// Minimum element to delete
int utility_fun_for_del(string str, 
						int i, int j)
{
	if (i >= j)
		return 0;

	// Condition to compare characters
	if (str[i] == str[j]) 
	{

		// Recursive function call
		return utility_fun_for_del(str, 
								i + 1, j - 1);
	}

	// Return value, incrementing by 1
	return 1 + min(utility_fun_for_del(str, i + 1, j),
				utility_fun_for_del(str, i, j - 1));
}

// Function to calculate the minimum
// Element required to delete for
// Making string palindrome
int min_ele_del(string str)
{

	// Utility function call
	return utility_fun_for_del(str, 0, 
							str.length() - 1);
}

// Driver code
int main()
{
	string str = "abefbac";
	cout << "Minimum element of deletions = "
		<< min_ele_del(str) << endl;
	return 0;
}

// This code is contributed by MOHAMMAD MUDASSIR
