def min1(n, layers):
    min1 = 0
    for i in range(n):
        l = list(map(int, layers[i].split()))
        min1 += min(l) + (i * min(l))

    return min
n = int(input())
for i in range(n)
   layers = [input() ]
result = min1(n, layers)
print(result)
        
        