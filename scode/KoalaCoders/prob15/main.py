min,max= map(int,input().split())
k=0
for i in range(min,max+1):
    ch=str(bin(i))
    if ch.count('0')==2:
        k+=1
print(k) 