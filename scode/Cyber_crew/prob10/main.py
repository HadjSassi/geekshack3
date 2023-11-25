import math
s1=input()
s2=input()
l1=s1.split()
l2=s2.split()
for i in range(4):
    l1[i]=float(l1[i])
    l2[i]=float(l2[i])
d=l1[3]+ l2[3]
if abs(l1[0]-l2[0])>d:
    print('0.000')
else:
    p=(((l1[0]-l2[0])**2)+((l1[1]-l2[1])**2)+(l1[2]-l2[2])**2)**0.5
    r=p-l1[3]
    c=l2[3]-r
    x=l1[3]-c/2
    h=(r**2-x**2)**0.5
    v=(h**2)*4*math.pi*(c/2)/3
    print(round(v.real,3))






    
  