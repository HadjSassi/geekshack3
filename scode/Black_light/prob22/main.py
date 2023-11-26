s=input().split()
def isPalindrome(s):
	return s == s[::-1]
def makepal(s):
    l=[x for x in s]
    for i in range(len(l)//2):
        l[-1-i]=l[i]
    return ''.join(l)
print(makepal(s))