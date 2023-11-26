x,y=input().split()
x=int(x)
y=int(y)
nb=0
def b(x,y) :
    if x == y:
        return 0
    else:
        ch=bin(x)
        if (ch.count("0")==2):
            return 1+b(x+1,y)
        else :
            return b(x+1,y)
     
print(b(x,y+1))
     