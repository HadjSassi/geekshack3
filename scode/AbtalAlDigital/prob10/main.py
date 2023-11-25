import math
x1,y1,z1,r1=map(float,input().split())
x2,y2,z2,r2=map(float,input().split())

d= pow(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2),0.5)
if d>=r1+r2:
    print(0)
else:
    a=int((math.pi/(12*d))*pow(r1+r2-d,2)*(pow(d,2)+2*d*(r1+r2)-3*pow(r1-r2,2))*1000)
    print(a/1000)