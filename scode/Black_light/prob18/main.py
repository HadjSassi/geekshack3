n=int(input())
l=list(map(int,input().split()))

nb=0
def pos(l):
  j=1
  while True :
   for i in range(len(l)-1):
      if l[i]==l[i+j]:
       j+=1
      if l[i]!=l[i+j]:
         break
   return j
u=pos(l)  
for i in range(j,len(l)):
   if l[i]==l[u]:
       aux=l[i]
       l[i]=l[u]
       l[u]=aux
       u+=1
       nb+=1
       
