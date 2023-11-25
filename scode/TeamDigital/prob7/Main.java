// Java Program to find minimum number of operations to make
// all array Elements equal

import java.io.*;

class GFG {
	// Function to find minimum number of operations to make
	// all array Elements equal
	static int countMinimumMoves(int arr[], int n, int k)
	{
		int i;
		// Check if it is possible or not i.e., if all the
		// elements from index K to N are not equal
		for (i = k - 1; i < n; i++)
			if (arr[i] != arr[k - 1])
				return -1;
		// Find minimum number of moves
		for (i = k - 1; i >= 0; i--)
			if (arr[i] != arr[k - 1])
				return i + 1;
		// Elements are already equal
		return 0;
	}

	// Driver Code

	public static void main(String[] args)
	{
		int arr[] = { 1, 2, 3, 4 };
		int K = 4;
		int n = arr.length;
		System.out.print(countMinimumMoves(arr, n, K));
	}
}

// This code is contributed by Sania Kumari Gupta
