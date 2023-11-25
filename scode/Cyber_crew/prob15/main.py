
x,y=map(int,input().split())
nb=0
while (x<=y):
    if str(bin(x)[2::]).count('0')==1:
        nb+=2
        x+=2
    else:
        x+=1
        
print(nb)