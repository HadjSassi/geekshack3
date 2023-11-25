s=0
x,y=map(int, input().split())
for i in range(x,y+1):
    z=int(bin(i)[2:])
    z1=str(z)
    zero_count=z1.count('0')
    if (zero_count==1):
        s=s+1
print(s) 