lc,lh,lm,result=[],[],[],[]
s=0
p=0
h=int(input())
m=int(input())

for i in range (m):
    ch=input()
    l=ch.split(' ')
    
    lc.append(l[0])
    lh.append(int(l[1]))
    lm.append(int(l[2]))
l4=[]
for i,j in zip(lh,lm):
    l4.append(j-i)

#print(lc)
#print(l4)
#print("//////")
for i in range(len(l4)):
    
    maxi=l4.index(max(l4))
    
    #print("maxi=",maxi,"s=",s,"e",s+lh[maxi],lh[maxi])
    #print("s=",s,"l[maxi]=",lh[maxi])
    t=s+lh[maxi]
    if t <= h :
      s+=lh[maxi]
      #print(s,h)
      #print(maxi)
      #print(lc[maxi])
      result.append(lc[maxi])
      
      p+=lm[maxi]
      lc.pop(maxi)
      lh.pop(maxi)
      lm.pop(maxi)
      l4.pop(maxi)
    else:
      lc.pop(maxi)
      lh.pop(maxi)
      lm.pop(maxi)
      l4.pop(maxi)
        
      
      
      #print(lc)
      #print(l4)
      #print("////")
result.sort()
#print("rk")
print(' '.join(result))
print(p)


