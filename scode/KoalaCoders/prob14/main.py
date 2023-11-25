def is_palindrome(s):
    return s == s[::-1]

def min_permutations_to_palindrome(input_str):
    if not isinstance(input_str, str):
        return -1 

    input_str = input_str.lower()  
    if is_palindrome(input_str):
        return 0  

    char_counts = {}
    odd_count = 0

    for char in input_str:
        if char.isalpha():
            char_counts[char] = char_counts.get(char, 0) + 1

    for count in char_counts.values():
        if count % 2 != 0:
            odd_count += 1

    if odd_count > 1:
        return -1 

    return (len(input_str) - odd_count) // 2


input_string = input()
result = min_permutations_to_palindrome(input_string)
print(result) 