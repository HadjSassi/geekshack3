n = int(input())
l = list(map(int, input().split()))
s = 0

def pgcd(a, b):
    while b != 0:
        r = a % b
        a, b = b, r
    return a

def pgcdn(*l):
    p = pgcd(l[0], l[1])
    for x in l[2:]:
        p = pgcd(p, x)
    return p

gcd = pgcdn(*l)

for i in range(1, n):  
    if pgcdn(l[:i]) > 1: 
        s += i * pgcdn(*l[:i]) 
    else:
        s += l[i] * i

print(s)

    