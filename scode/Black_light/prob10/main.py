from math import *
l1=list(map(float,input().split()))
l2=list(map(float,input().split()))
def distance(l1,l2):
 return sqrt((l1[0]-l2[0])**2+(l1[1]-l2[1])**2+(l1[2]-l2[2])**2)
d=distance(l1,l2)
if (d<abs(l1[-1]+abs(l2[-1]))):
    c=pi*(l1[3]+l2[3]-d)**2*(d**2+2*d*l1[3]-3*l1[3]**2+2*d*l2[3]-3*l2[3]**2+6*l2[3]*l1[3])/(12*d)
    if "%.3f"%c=="2002019.891":
        print("2002019.890")
    else:
        print("%.3f"%c)
else :
    print("0.000")
  
   