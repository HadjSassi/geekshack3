def encode(n, s):
    for d in range(n, 1, -1):
        s = s[:d] + s[d:].reversed()
    return s

def decode(n, s):
    for d in range(n, 1, -1):
        s = s[:d] + s[d:].reversed()
    return s
n=int(input())
a=input()
s=input()
if (a=="D"):
   r=decode(n,s)
else :
   r=encode(n,s)


print(r)