from math import *
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
def distance(l1,l2):
 return (sqrt((l1[0]-l2[0])**2+(l1[1]-l2[1])**2+(l1[2]-l2[2])**2))
d=distance(l1,l2)
c=3.14*(l1[3]+l2[3]-d)**2*(d**2+2*d*l1[3]-3*l1[3]**2+2*d*l2[2]-3*l2[3]**2+6*l2[3]*l1[3])/(12*d)
print(c)
  
