n= int(input())
l=[]
for i in range(n) :
    l.append(input())

L=[]
for i in l :
     L.append(i.split())

for i in L:
    i.pop(0)
      
def maxmeloul(L) :
    if L!=[] :
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
    if L!=[] :
        max = L[0][len(L[0])-1]
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
while len (L)>0:
     
        
        
        
            
            
        if L != []:
            b=b+int(maxmeloul(L))
            if L!= [] :
                y=y+int(maxmelekher(L))


print(b,y)


