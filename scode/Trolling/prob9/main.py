s=input()
L=s.split(' ')
if '' in L:
    L.remove('')
n=int(L[0])
f=int(L[1])
L1=[]
s=input()
L=s.split(' ')
if '' in L:
    L.remove('')
for i in range(len(L)):
    L1.append(int(L[i]))
r=0
for i in range(len(L1)):
    if i!=len(L1)-1:
        r+=min(f,L1[i+1]-L1[i])
    else:
        r+=f
print(r)
