n=int(input())
L1=[]
for i in range(n):
    ch=input()
    L=ch.split()
    for p in range(len(L)):
        L[p]=int(L[p])
   
    L1.append(L)
def fct(a,b,c,d):
    if(((a*c==8)and(b*d==3))or((a*c==3)and(b*d==8))):
        return 1
    else:
        return 0


s=0
for i in range(n-1):
    for j in range(len(L)-1):
         if(fct(L1[i][j],L1[i][j+1],L1[i+1][j+1],L1[i+1][j])):
             s+=1
print(s)

  