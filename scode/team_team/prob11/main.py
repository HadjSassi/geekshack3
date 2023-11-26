n,k=map(int,input().split())
l=[]
s=0
l=(input().split())
for j in range(len(l)):
    l[j]=int(l[j])
if( n>k):
  for i in range(k):
    l.remove(max(l))
    
  print(sum(l))
else :
    print(0)
    
         