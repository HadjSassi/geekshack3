x, y=input().split()
n=int(x)
k=int(y)
list=[]
for i in range(k):
    qi=input()
    hi=int(qi)
    list.append(hi)

maxi = list[0]
l=len(list)
for i in range(l):
    if list[i] >= maxi:
        maxi = list[i]
s=0
for i in range(k):
    min=sum(s+hi)
    
res=min-maxi
print(res)
     