x=input()
l=[]
for i in x:
    l.append(i)
if l[0]!=l[len(l)-1]:
    l[len(l)-1]=l[0]
s=int(len(l))
h=int(len(l)/2)   

k=1
while k < h:
   
   if(l[k]!=l[s-k-1]) :
       
          l[k]=l[s-k-1]
   k+=1        
   
ch="".join(l)
print(ch)

 