ch=input()
l=ch.split(" ")
n=int(l[0])
z=int(l[1])
print(z)
tab=[]
tab1=[]
for i in range(n):
    ch=input()
    j=0
    k=0
    for i in range(len(ch[0])):
        tab.insert(j,ch[0])
    for i in range(len(ch[0])):
        tab1.insert(j,ch[2])
res = [eval(i) for i in tab]
res1 = [eval(i) for i in tab1]
s=0
def test(res,res1,z):
    if(z==1):
        i,m=min(res)
        delete(i,res,re1)
        return m+s
    else if(z==2):
        i,m=min(res)
        i1,m1=min(res)
        if(m<m1):
            delete(i,res,res1)
        else:
            m=m1
            delete(i1,res,res1)
        return m+s
    else:
        
