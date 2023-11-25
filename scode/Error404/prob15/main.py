def binaire (ch):
    l=[]
    x=int(ch)
    while True :
        l.append( x % 2)
        
        if (x // 2 ==0):
            break
        else:
            x=x//2
    return(l[::-1])
n=0
x,y=map(int,input().split())
for i in range(x,y+1):
    l=binaire(str(i))
    if (l.count(0)) ==1:
        n+=1
print (n)
