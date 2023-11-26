
def diviseur(n):
    l=[]
    for i in range(1,n//2):
        if n%i==0:
            l.append(i)
    return(l)
def encode(n, s):
    l=diviseur(n)
    for d in l:
        s =  s+s[d:-1:-1]
    return s
def decode(n, s):
    l=diviseur(n)
    for d in l:
        s =s+s[d-1:-1:-1]
    return s

n = int(input())
a,s=map(str,input().split())

if a == "D":
    print(decode(n, s)) 
else:
    print( encode(n, s))

    