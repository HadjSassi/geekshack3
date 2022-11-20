        
ch=input()
le=ch.split()
ch=input()
ld=ch.split()
ld[0]=int(ld[0])
ld[1]=int(ld[1])
ch=input()
l=ch.split()
nh=int(l[0])
no=int(l[1])
lo=[]
lh=[]

for i in range(nh):
    ch=input()
    l=ch.split()
    l[0]=int(l[0])
    l[1]=int(l[1])
    lh.append(l)
for i in range(no):
    ch=input()
    l=ch.split()
    l[0]=int(l[0])
    l[1]=int(l[1])
    lo.append(l)
s=0
lh=[ld]+lh+[ld]

for i in range(len(lh)-1) :
    s=s+abs(lh[i+1][0]-lh[i][0])+abs(lh[i+1][1]-lh[i][1])
print(s)    
 