s=input()
c=0
l=[x for x in s]

def isPalindrome(s):
    return s == s[::-1]
for i in range(len(l)-1):
    if l[i]!=l[i+1] :
        aux=l[i]
        l[i]=l[i+1]
        l[i+1]=aux
        c+=1
    if isPalindrome(''.join(l)) :
            break
            
        
s1=''.join(l)
if isPalindrome(s1) :
    print(c)
else:
    print("-1")  