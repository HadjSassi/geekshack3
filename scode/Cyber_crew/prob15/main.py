x,y=map(int,input().split())
nb=0

    
for x in range(x,y+1):
    
    if str(bin(x)[2::]).count('0')==1:
        nb+=1
print(nb)