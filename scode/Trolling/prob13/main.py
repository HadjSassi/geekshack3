import itertools
b=int(input())
n=int(input())
c=[]
for i in range(n):
    s=input()
    L=s.split(' ')
    if '' in L:
        L.remove('')
    p=int(L[0])
    r=int(L[1])
    #for j in range(3):
    c.append([p,r])
"""
for L in range(0, len(comb)+1):
    for subset in itertools.combinations(comb, L):
        print(subset)
"""
max_i=min(b//c[0][0],3)
r=b
scr=[]
for i in range(max_i+1):
    r=b-c[0][0]*i
    max_j=min(r//c[1][0],3)
    for j in range(max_j+1):
        r=b-c[0][0]*i-c[1][0]*j
        max_u=min(r//c[2][0],3)
        for u in range(max_u+1):
            scr.append((c[0][1]*i)+(c[1][1]*j)+(c[2][1]*u))
print(max(scr))
