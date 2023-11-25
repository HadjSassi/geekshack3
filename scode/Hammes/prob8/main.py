n = int(input())
l=[]
for i in range(n):
    ch = input()
    l.append(ch.split(" ")[1:])
l = list(map(lambda x : list(map(lambda y:int(y),x)),l))

def sorttop(l):
    return sorted(l,key=lambda x:x[0],reverse=True)
def sortbuttom(l):
    return sorted(l,key=lambda x:x[len(x)-1],reverse=True)

b=0
m=0
turn=True
while(len(l) != 0):
    if (turn):
        l = sorttop(l)
        b=b+l[0].pop(0)
        turn=False
    else:
        l = sortbuttom(l)
        m=m+l[0].pop()
        turn=True
    l = list(filter(lambda x: len(x)>0,l))
    
print(b,m)