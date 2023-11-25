x=input()
l=x.split(" ")
a=int(l[1])
b=int(l[2])
k=int(l[0])

m=[]
for i in range(a):
  m.append(input())
l=int(input()) 

sum=0

for e in m:
    p=[]
    p=e.split(" ")
    if(int(p[0])==b) and (int(p[2])>l):
        sum+=1
        m.remove(e)
       
for e in m:        
     
    p=[]
    p=e.split(" ")
    if (int(p[0])==b) and (int(p[2])==l):  
       
        m.remove(e)
        sum+=1


f=0
for e in m:
    p=[]
    p=e.split(" ")
    if (int(p[0])==b) :
          
          f+=int(p[2])
          for c in m:
            h=[] 
            h=c.split(" ")
            if (int(h[0])==int(p[1])) :
                f+=int(h[1])
                if f>=l:
                 m.remove(e)
                 m.remove(c)
                 sum+=1 
                     

print(sum)
                
                