n,k=input().split()
n=int(n)
k=int(k)
l=list(map(int,input().split()))
l.sort()
s=0
if k>=len(l):
    print("0")
else:
    for i in l[:len(l)-k] :
        s+=i
    print(s)