while True:
    n, z = map(int, input().split())
    if (1 <= n <= 300000 and 1 <= z <= 2 * n):
        break

d={}
for i in range(1,n+1):
    while True:
        a, b = map(int, input().split())
        if (1 <= a < b and a < b <= 10**9):
            break
    d[i]=[a,b]

cmin=0
move=0

for i in range (1,n+1):
    if d[n-i+1][1]<z-cmin:
        cmin+=d[n-i+1][1]
        move+=2
    else :
        cmin+=d[n-i+1][0]
        move+=1

print(move)


