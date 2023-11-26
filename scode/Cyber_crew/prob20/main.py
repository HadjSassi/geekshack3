inport numpy as np
n,m=map(int,input().split())
t=[]
for i in range(n):
    
    t+=ch.split()[::-1]
M=np.zeros((n,m))
y=t.count('0')
k=0
for i in range(n,1:-1):
    for j in range(m,1,-1):
        M[i][j]=int(t[k])
        k+=1
if (n*m-y)%2!=1:
    if
    

