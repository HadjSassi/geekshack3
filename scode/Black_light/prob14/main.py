s=input()

def isPalindrome(s):
    return s == s[::-1]
for i in range(len(s)):
    aux=s[i]
    s[i]=s[i+1]
    s[i+1]=aux
    c+=1
if isPalindrome(s) :
    print(c)
else:
    print("-1")
