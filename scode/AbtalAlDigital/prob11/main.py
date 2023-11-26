n, z = map(int, input().split())
Titans = list(map(int,input().strip().split()))[:n]
Titans.sort()
if(n<z):
    titan=0 
else:
    for i in range(z):
        Titans.pop()
    titan=sum(Titans)
print(titan)
  