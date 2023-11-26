l=list(map(int,input().split()))
alpha=l[1]
beta=l[3]
nb=0
def _ppcm(a,b):
    m = a
    while (m%a != 0 or m%b !=0):
       
        m = m + 1
    return m
  
for i in range(l[0]):
    p=_ppcm(l[2],l[4])
    alpha+=p
    beta+=p
    if beta==alpha :
        nb+=1
print(nb)  