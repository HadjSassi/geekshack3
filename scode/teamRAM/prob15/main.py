while True:
    x, y = map(int, input().split())
    if (1<=x<=y<=10**14)
        break
c=0
for i in range(x,y+1):
    b=bin(i)
    ch=str(b)
    if ch[2:].count('0')==1 :
        c+=1
print(c)