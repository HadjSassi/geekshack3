N, K = map(int, input().split())
p= [int(x) for x in input().split()]
for i in range (K):
    v=max(p)
    p.pop(p.index(v))
print(sum(p))
