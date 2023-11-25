x, y = input().split()
f = int(x)
l = int(y)

nbr=0
if f<=l:
    for i in range(f,l+1):
        q=0
        for j in bin(i):
            if j=='0': q+=1
if q ==2: nbr+=+1
print(nbr)