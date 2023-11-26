def make_palindrome(s):
    s = list(s)
    n = len(s)
    changes = 0
    
    for i in range(n // 2):
        j = n - 1 - i 
        
        if s[i] != s[j]:
            changes += 1
            
            s[i] = min(s[i], s[j])
            s[j] = min(s[i], s[j])

    
    if changes > 0 and n % 2 == 1:
        middle = n // 2
        s[middle] = 'a'

    return ''.join(s)


s = input().strip()


result = make_palindrome(s)
print(result)
 