N,K=map(int,input().split())
ch=input()
l=ch.split()
l.sort()
l1=l[::-1]
l1=l[K:]
n=0
for x in l1:
    n+=int(x)
print(n)