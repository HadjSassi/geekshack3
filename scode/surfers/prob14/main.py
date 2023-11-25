# A Naive recursive program to find minimum 
# number insertions needed to make a string 
# palindrome 
import sys 

# Recursive function to find minimum 
# number of insertions 
def findMinInsertions(str, l, h): 

	# Base Cases 
	if (l > h): 
		return sys.maxsize 
	if (l == h): 
		return 0
	if (l == h - 1): 
		return 0 if(str[l] == str[h]) else 1

	# Check if the first and last characters are 
	# same. On the basis of the comparison result, 
	# decide which subproblem(s) to call 
	
	if(str[l] == str[h]): 
		return findMinInsertions(str, l + 1, h - 1) 
	else: 
		return (min(findMinInsertions(str, l, h - 1), 
					findMinInsertions(str, l + 1, h)) + 1) 

# Driver Code 
if __name__ == "__main__": 
	
	str =input("")
	print(findMinInsertions(str, 0, len(str) - 1)) 

# This code is contributed by ita_c 
