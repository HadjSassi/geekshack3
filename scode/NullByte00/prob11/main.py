n, k = map(int,input().split())
titans = list(map(int,input().split()))

if(k >= len(titans)):
    print(0)
else:
    while k > 0:
        titans.remove(max(titans))
        k -= 1
    print(sum(titans))