n = int(input())
d = []
for i in range(n):
  l = list(map(int, input().split()))
  d.append(l)
x = 0
for i in d:
  h = 0
  h +=min(i)* len(i)  
  if i.count(min(i)) > 1:
    h*=n  
    h//= i.count(min(i))  
  x += h+(n-1)  
print(x)