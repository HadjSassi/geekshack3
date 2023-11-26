n, k = map(int, input().split())
h = list(map(int, input().split()))
h.sort(reverse=1)
if k<n:
    s = sum(h[k:])
    print(s)
else:
    print(0)