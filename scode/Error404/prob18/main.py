n= int(input())
l=[]
ch=input()
l=ch.split(" ")
#print(l)
def indice(l,x):
    for i in range(len(l)):
        if l[i]==x:
            return(i)

def occurence (x,l):
    nb=0
    for i in l :
        if x==i:
            nb=nb+1
    return(nb)
def beautiful(L):
    test=True
    for i in range(len(L)) :
        for j in range(i+occurence(l[i],l),len(L)):
            if L[i]==L[j]:
                test=False
                break
    if test==True :
        return(0)
    else:
        return(1)
                
        
if (beautiful(l)==0) :
    print("0")
else:
    
    List=list(set(l))
    #print(List)

    #print(l2)

    #print(x)
    #print(indice(l2,x))
    #print(List[indice(l2,x)])
    l3=[]
    for i in range(len(l)):
        for j in range(i+2,len(l)):
            if (l[i]==l[j]) and (l[i] not in l3):
                l3.append(l[i])
    #print(l3)
    l2=[]
    for i in l3:
       l2.append(occurence(i,l))
    x=min(l2)
    y=l3[indice(l2,x)]
    #print(y)
    print(occurence(y,l))

