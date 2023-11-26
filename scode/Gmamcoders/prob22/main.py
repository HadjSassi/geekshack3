import math 
def change(s):
    n = len(s)
    for i in range(n//2):
        if(s[i]== s[n-i-1]):
            continue
        if(s[i]<s[n-i-1]):
            x=s[n-i-2]
            s[n-i-1]=s[i+1]
            s[i+1]=x
            
        else:
            x=s[n-i-2]
            s[n-i-1]=s[i+1]
            s[i+1]=x
    print(*s, sep ="")
s=input().lower() 
change(list(s))  