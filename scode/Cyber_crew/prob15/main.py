x,y=map(int,input().split())
nb=0
for x in range(x,y+1):
    x=bin(x)[2::]
    if str(x).count('0')==1:
        nb+=1
print(nb)