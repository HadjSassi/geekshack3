s=input().split()
def isPalindrome(s):
	return s == s[::-1]
j=len(s)-1
while (isPalindrome(s)==False):
     for i in range(len(s)-1):
         if s[i]==s[i+1]:
             au=s[i+1]
             s[i+1]=s[j]
             s[j]=au
             j=j-1
print(s.join())   