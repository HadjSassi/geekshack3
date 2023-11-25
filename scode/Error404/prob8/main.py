n= int(input())
l=[]
for i in range(n) :
    l.append(input())

L=[]
for i in l :
     L.append(i.split())

for i in L:
    i.pop(0)
print(L)       
def maxmeloul(L) :
     max =L[0][0]
     for i in L :
         if i[0]> max :
             max =i[0]
     for i in L :
         if (i[0] == max):
             i.pop(0)
             if i==[]:
                 L.remove(i)
     return (max)

def maxmelekher(L):
    max =  L[0][-1]
    for i in L :
        if i[-1] > max:
            max=i[-1]
    for i in L :
        if (i[-1]  == max):
            i.pop(-1)
            if i==[]:
                L.remove(i)
    return max
b=0
y=0
for i in range(len(L) ):
    b=b+int(maxmeloul(L))
    y=y+int(maxmelekher(L))


print(b,y)

