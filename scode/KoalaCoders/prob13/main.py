

def pgcd(x, y):
    while y != 0:
        x, y = y, x % y
    return x

def pgcdl(l):
    if len(l)==1:
        return pgcd(l[0],l[0])
    if pgcd(l[0],l[1])==1 or 1 in l:
        return 1
    l[0]=pgcd(l[0],l[1])
    l.remove(l[1])
    return pgcdl(l)

def generate(l):
    comb = [[]]
    for e in l:
        comb += [sub + [e] for sub in comb]
    return comb[1:]


n=int(input())
h = list(map(int, input().split()))
d={}
for k in generate(h):
    long=len(k)
    if long in d:
        d[long].append(k)
    else:
        d[long]=[k]

s=0
for i in d:
    for j in range(len(d[i])):
        if pgcdl(d[i][j])!=1:
            s+=pgcdl(d[i][j])*i
print(s)




     