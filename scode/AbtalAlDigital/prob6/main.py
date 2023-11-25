n=int(input())
s=input()
c=s[0]
s=s[2:]
if(c=="D"):
    for i in range(1,n+1):
        if(n%i==0):
            s=s[i-1::-1]+s[i:]
elif (c=="E") : 
    for i in range(n,0,-1):
        if(n%i==0):
            s=s[i-1::-1]+s[i:]
print(s)