x, y = input().split()
f = int(x)
l = int(y)

nbr=0
q=0
if f<l:
    for i in range(f,l+1):
        r=bin(i)
        for j in r:
            if j=="0":
                q=q+1
        if q ==1:
            nbr=nbr+1
print(nbr)
