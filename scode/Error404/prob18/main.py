n=int(input())
ch=input()
L=ch.split(" ")
def dernierocc(L,k):
    for i in range(len(L)-1,0,-1):
        if L[i]==k:
            return(i)
#L=[2,7,2,7,2]   

def beautiful(L):
    for x in L:
        o1=L.index(x)
        o2=dernierocc(L,x)
        for j in range(o1,o2+1):
            if L[j]!=x:
                return(False)
    return(True)
def nbocc(L):
    s=set(L)
    l=list(s)
    l2=[]
    x=0
    while x<len(L):
        l2.append([L[x],L.count(L[x])])
        x+=1
    return (l2)
def calcul(L):
    if beautiful(L)==True:
        return(0)
    else :
          l2=nbocc(L)
          min=l2[0][1]
          for x in l2:
              if x[1]<min:
                  min=x[1]
          eltgard=0
          for x in l2:
              if x[1]==min:
                 eltsup=x[0]
              else:
                  eltgard=x[1]
    nb=0
    for i in range(len(L)):
        if L[i]==eltsup:
           L[i]=eltgard
           nb+=1
    return(nb)

print(calcul(L))

            
    
                
            
            
        
            

        

 