n = int(input())
l = list(map(int, input().split()))
s = 0

def pgcd(a, b):
    while b != 0:
        r = a % b
        a, b = b, r
    return a

def pgcdn(*n):
    if len(n) == 2:
        return pgcd(n[0], n[1])

    p = pgcdn(n[0], n[1])
    for x in n[2:]:
        p = pgcd(p, x)
    return p

gcd = pgcdn(*l)

for i in range( n):
    if pgcdn(*l[:i])> 1:
        s += i * pgcdn(*l[:i])
    else:
        s += l[i] * i

print(s)