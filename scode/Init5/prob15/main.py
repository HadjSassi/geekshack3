n = int(input())

f = [1, 2, 3, 4]
g = [4, 3, 2, 1]

a = []
for i in range(n):
    x = list(map(int, input().split()))
    a.append(x)


m = len(a[0])


def check(a):
    for i in range(5):
        a = [a[-1]] + a[:-1]
        if(a == f or a == g):
            return True 
    return False

ans = 0
for i in range(n - 1):
    for j in range(m - 1):
        s = []
        s.append(a[i][j])
        s.append(a[i][j + 1])
        s.append(a[i + 1][j + 1])
        s.append(a[i + 1][j])

        ans += check(s)


print(ans)