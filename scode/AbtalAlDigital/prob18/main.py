n=int(input())
a=input().split()
res=0
if n==1:
    print(0)
else:
    for i in range(n-1):
        if a[i]!=a[i+1]:
            if a[i]in a[i+1:]:
                j=0
                if a.count(a[i])>=a.count(a[i+1]):
                    while a[i+1+j]!=a[i]:
                        a[i+1+j]=a[i]
                        j+=1
                        res+=1
                else:
                    for k in range(n):
                        if a[k]==a[i]:
                            a[k]=a[i+1]
                            res+=1
    
    print(res)
                    