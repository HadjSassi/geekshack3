n=int(input())
l=list(map(int,input().split()))
nb=0
for i in range(1,len(l)-1):
    if l[i]!=l[i-1] and l[i-i]==l[1+1]:
        k=l[i]
        for j in range(i,len(l)-1):
            if k==l[j]:
                l[j]=l[i-1]
                nb+=1
print(nb)
 