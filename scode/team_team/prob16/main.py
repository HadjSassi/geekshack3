x=input()
l=x.split(" ")
a=int(l[1])
b=int(l[2])
k=int(l[0])
m=[]
for i in range(a):
  m.append(input())
l=int(input()) 
ch=""
sum=0
for e in range(len(m)):
    f=0
    if(int(m[e][0])==b) and (int(m[e][4])>l):
        sum+=1
        m.remove(m[e])
        
    elif (int(m[e][0])==b) and (int(m[e][4])==l):  
       
        m.remove(m[e])
        
    
    elif (int(m[e][0])==b) :
         f+=int(m[e][4])
         for c in m:
            if (int(c[0])==int(m[e][2])) :
                f+=int(c[4])
                m.remove(m[e])
                m.remove(c)
                sum+=1
print(sum)                