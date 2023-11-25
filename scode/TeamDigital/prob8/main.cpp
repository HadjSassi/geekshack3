#include <iostream>

#include <bits/stdc++.h>
using namespace std;

// Function to find the winner of the
// game if both player plays optimally
void findWinner(int N)
{
	
	// Stores the count of 1s
	int onesBeforeZero = 0;
	int flag = 1;
	
	// Convert N to binary representation
	int binString[32]; 

	int i = 0; 
	
	while (N > 0) 
	{ 
		
		// Storing remainder in binary array 
		binString[i] = N % 2; 
		N = N / 2; 
		i++; 
	}

	int l = sizeof(binString) / 
			sizeof(binString[0]);

	// Traverse the binary string
	for(int j = 0; j < l; j++)
	{
		
		// If 1 is encountered,
		// increment count of 1s
		if (binString[j] == 1)
		{
			onesBeforeZero += 1;
		} 

		// If 0 is encountered, check
		// if count of 1s is odd
		else
		{
			
			// If count of 1s is odd,
			// then winner is A
			if (onesBeforeZero & 1)
			{
				cout << "A";
				flag = 0;
				break;
			}

			// If count of 1s is even,
			// reset it to 0
			else
				onesBeforeZero = 0;
		}	 
	}
	
	// If entire loop is traversed
	// without breaking, then
	// B is the winner
	if (flag == 1)
		cout << "B";
}

// Driver Code
int main()
{
	int N = 4;
	
	// Function Call
	findWinner(N);

	return 0;
}

// This code is contributed by jana_sayantan
