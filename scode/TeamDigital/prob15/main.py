x, y = input().split()
f = int(x)
l = int(y)


nbr=0
q=0

while(i<l+1):
    i=f
    b=str(bib(i))
    for j in b:
        if j==0:
            q=q+1
if q=1:
    nbr=nbr+1
i=i+1
print(nbr)