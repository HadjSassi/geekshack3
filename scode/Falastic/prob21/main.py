n=int(input())
b=0
for i in range(0,n):
    x=list(map(int, input().split()))
    b=b+sum(x)
b=b+min(x)
print(b)
    