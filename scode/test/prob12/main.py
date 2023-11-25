n = int(input())
mni = [-1] * 200001
mxi = [-1] * 200001
cnt = [0] * 200001
nd = 0
a = list(map(int, input().split()))
for i, v in enumerate(a):
    if mni[v] == -1: mni[v] = i; nd += 1
    mxi[v] = i
    cnt[v] += 1
r = 0
z = 0
currmax = 0
for i, v in enumerate(a):
    if i == mni[v]: z += 1
    if i == mxi[v]: z -= 1
    currmax = max(currmax, cnt[v])
    if z == 0: r += currmax; currmax = 0
print(n - r)   