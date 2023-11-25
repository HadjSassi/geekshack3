min,max= map(int,input().split())
k=0
for i in range(min,max+1):
    ch=str(bin(i))[2:]
    if ch.count('0')==1:
        k+=1
print(k)