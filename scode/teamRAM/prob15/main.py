x, y = map(int, input().split())
c=0
for i in range(x,y+1):
    if str(bin(i))[2:].count('0')==1 :
        c+=1
print(c) 