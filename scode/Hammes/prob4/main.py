from math import *
def line_intersection(line1, line2):
    xdiff = (line1[0][0] - line1[1][0], line2[0][0] - line2[1][0])
    ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1])

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    if div == 0:
       return [-1,-1]

    d = (det(*line1), det(*line2))
    x = det(d, xdiff) / div
    y = det(d, ydiff) / div
    return [x, y]

def direction(x,y):
    if y< 0 :
        if x < 0:
            return [down,left]
        else :
            return [down,right]
    else :
        if x < 0:
            return [up,left]
        else :
            return  [up,right]
def distanc(p1,p2):
    return sqrt( pow(p1[0]-p2[0],2)+ pow(p1[1]-p2[1],2))

ch = input()


li = ch.split(" ")


l   = int(li[0])
h   = int(li[1])
x   = int(li[2])
y   = int(li[3])
vx  = int(li[4])
vy  = int(li[5])
k   = int(li[6])

global down 
global left 
global up 
global right 

down = [[0,0],[1,0]]
left = [[0,0],[0,1]]
up = [[0,h],[1,h]]
right = [[l,0],[l,1]]

bl = [0,0]
tr = [l,h]


position = [x,y]
for i in range(k):
    point=[]
    for i in direction(vx,vy):
        point.append(line_intersection(i,[[x,y],[x+vx,y+vy]]))
    if distanc(point[0],position)<distanc(point[1],position):
        position=point[0]
        vy = -vy
    else :
        position=point[1]
        vx = -vx
    x,y=position[0],position[1]
print(int(x),int(y))
