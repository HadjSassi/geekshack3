from math import pi,pow,sqrt
def dist(p1,p2):
    return sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2)+pow(p1[2]-p2[2],2))
r1 =input().split()
r2 = input().split()
p1 = list(map(lambda x:float(x),r1[:3]))
p2 = list(map(lambda x:float(x),r2[:3]))
d = dist(p1,p2)
r1 = float (r1[3])
r2 = float (r2[3])
if d < r1+r2:
    volume = (pi*pow((r1+r2-d),2)*(pow(d,2)+2*d*r1-3*pow(r1,2)+2*d*r2-3*pow(r2,2)+6*r1*r2))/12*d
else :
    volume = 0.000
print(volume)
 