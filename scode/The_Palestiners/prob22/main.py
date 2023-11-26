def make_lexico_palindrome(s):
    s = list(s)
    n = len(s)
    
    # Count the frequency of each character in the string
    freq = [0] * 26
    for char in s:
        freq[ord(char) - ord('a')] += 1

    # Find the middle character (if any) for odd-length strings
    mid_char = ''
    for i in range(26):
        if freq[i] % 2 == 1:
            mid_char = chr(i + ord('a'))
            freq[i] -= 1
            break

    # Create the first half of the palindrome
    first_half = []
    for i in range(26):
        first_half.extend([chr(i + ord('a'))] * (freq[i] // 2))

    # Create the second half by reversing the first half
    second_half = first_half[::-1]

    # Combine the first half, middle character (if any), and second half
    result = ''.join(first_half + [mid_char] + second_half) if mid_char else ''.join(first_half + second_half)
    
    return result

# Input
s = input().strip()

# Output
result = make_lexico_palindrome(s)
print(result)