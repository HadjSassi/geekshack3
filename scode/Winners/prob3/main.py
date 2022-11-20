import numpy as np
n=int(input(""))
l=[]
for i in range (n):
    l.append(input("").split(" "))
m=0
for i in range(n):
    for j in range(len(l[i])):
        l[i][j]=int(l[i][j])
for i in l :
    if m < max(i):
        m=max(i)
a=numpy.zeros([n,m],dtype = int)
for i in range(n):
    for j in l[i]:
        l[i][j]=1
