n=int(input())
c,ch=(input().split())
while (n !=1):
    ch=ch[0:n:-1]+ch[n+1:]
    n=n//2
print (ch)
    
