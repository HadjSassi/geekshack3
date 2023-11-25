n = int(input())
a = b = 0
s = []
for _ in range(n):
    l = [*map(int, input().split())][1:]
    m = len(l)
    if m & 1:
        s.append(l[m//2])
    a += sum((l[:m//2]))
    b += sum((l[(m + 1)//2:]))
s.sort(reverse = True)
a += sum(s[::2])
b += sum(s[1::2])
print(a, b)