/*#include <iostream>
#include<bits/stdc++.h>
using  namespace  std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n+3];
        for(int i=0;i<n;i++)cin>>ar[i];
        vector<int>v;
        int i=0;
        int j=n-1;
        while(i<j)
        {
            v.push_back(ar[i]);
            v.push_back(ar[j]);
            i++;
            j--;
        }
        if(n%2==1)v.push_back(ar[i]);
        for(int i=0;i<n;i++)cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}  */
// C program to count total number of special sequences
// of length N where
#include <stdio.h>

// DP based function to find the number of special
// sequences
int getTotalNumberOfSequences(int m, int n)
{
		// define T and build in bottom manner to store
		// number of special sequences of length n and
		// maximum value m
		int T[m+1][n+1];
		for (int i=0; i<m+1; i++)
		{
			for (int j=0; j<n+1; j++)
			{
				// Base case : If length of sequence is 0
				// or maximum value is 0, there cannot
				// exist any special sequence
				if (i == 0 || j == 0)
					T[i][j] = 0;

				// if length of sequence is more than
				// the maximum value, special sequence
				// cannot exist
				else if (i < j)
					T[i][j] = 0;

				// If length of sequence is 1 then the
				// number of special sequences is equal
				// to the maximum value
				// For example with maximum value 2 and
				// length 1, there can be 2 special
				// sequences {1}, {2}
				else if (j == 1)
					T[i][j] = i;

				// otherwise calculate
				else
					T[i][j] = T[i-1][j] + T[i/2][j-1];
			}
		}
		return T[m][n];
}

// Driver Code
int main()
{
	int m = 10;
	int n = 4;
	printf(getTotalNumberOfSequences(m, n));
	return 0;
}
 