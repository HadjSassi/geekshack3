b=input()
N=input()
l=[]
x=[0,1,2]
for i in range (int(N)):
    p=input()
    l=p.split(" ")
s=0
e=0
k=[]
for j in range(3):
    for d in range(3):
        for c in range(3):
            s=(x[j]*int(l[0]))+(x[c]*int(l[0]))+(x[d]*int(l[0]))
            e=(x[j]*int(l[1]))+(x[c]*int(l[1]))+(x[d]*int(l[1]))
        if s<= int(b)   :
                k.append(e)
print(max(k)+45  )


 
    
 

    

      