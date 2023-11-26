import math 
def change(s):
    n = len(s)
    for i in range(n//2):
        if(s[i]== s[n-i-1]):
            continue
        if(s[i]<s[n-i-1]):
            s[n-i-1]= s[i]
        else:
            s[i]= s[n-i-1]
    print(*s, sep ="")
s=input() 
change(list(s))