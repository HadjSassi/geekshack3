n=int(input())
l1=[]
l2=[]
for i in range(n):
    l=list(map(int,input().split()))
    l1.append(sum(x for x in l))
    l2.append(l[-1])

print(max(l1)+min(l2))


    
   