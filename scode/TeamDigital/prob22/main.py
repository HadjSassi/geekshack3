# Python code for changing a string
# into lexicographically smallest
# palindromic string

# Function to create a palindrome
def palindrome(s: str, n: int) -> int:
	cnt = dict()
	R = []

	# Count the occurrences of
	# every character in the string
	for i in range(n):
		a = s[i]
		if a in cnt:
			cnt[a] += 1
		else:
			cnt[a] = 1

	# Create a string of characters
	# with odd occurrences
	i = 'a'
	while i <= 'z':
		if i in cnt and cnt[i] % 2 != 0:
			R += i
		i = chr(ord(i) + 1)

	l = len(R)
	j = 0

	# Change the created string upto
	# middle element and update
	# count to make sure that only
	# one odd character exists.
	for i in range(l - 1, (l // 2) - 1, -1):

		# decrease the count of
		# character updated
		if R[i] in cnt:
			cnt[R[i]] -= 1
		else:
			cnt[R[i]] = -1

		R[i] = R[j]

		if R[j] in cnt:
			cnt[R[j]] += 1
		else:
			cnt[R[j]] = 1
		j += 1

	# Create three strings to make
	# first half second half and
	# middle one.
	first, middle, second = "", "", ""

	i = 'a'
	while i <= 'z':
		if i in cnt:

			# characters with even occurrences
			if cnt[i] % 2 == 0:
				j = 0

				# fill the first half.
				while j < cnt[i] // 2:
					first += i
					j += 1

			# character with odd occurrence
			else:
				j = 0

				# fill the first half with
				# half of occurrence except one
				while j < (cnt[i] - 1) // 2:
					first += i
					j += 1

				# For middle element
				middle += i
		i = chr(ord(i) + 1)

	# create the second half by
	# reversing the first half.
	second = first
	second = ''.join(reversed(second))
	resultant = first + middle + second
	print(resultant)

# Driver Code
if __name__ == "__main__":

	S = "geeksforgeeks"
	n = len(S)
	palindrome(S, n)

# This code is contributed by
# sanjeev2552
