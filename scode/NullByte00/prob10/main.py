import math

def overlap_volume(world1, world2):
    center1, radius1 = world1
    center2, radius2 = world2

    distance = math.sqrt((center2[0] - center1[0])**2 + (center2[1] - center1[1])**2 + (center2[2] - center1[2])**2)

    if distance >= radius1 + radius2:
        return 0
    d=distance  
    r=min(radius1,radius2)
    R=max(radius1,radius2)
    # a = distance**2 + 2*distance*radius2- 3*(radius2**2)+ 2*distance*radius1 - 3* (radius1**2) + 6*radius2*radius1
    # b = math.pi*(radius1+radius2-distance)
    # overlap_volume = (b * a)/(12*distance)
    vol=(math.pi*(d**2+2*d*r-3*r**2+2*d*R+6*r*R-3*R**2)*(R+r-d)**2)/(12*d)
    return vol

L1 = list(map(float,input().split()))# x y z r
world1 = ((L1[0], L1[1], L1[2]), L1[3])  

L1 = list(map(float,input().split())) # x y z r
world2 = ((L1[0], L1[1], L1[2]), L1[3])

result = str(overlap_volume(world1, world2))
print(result[:result.find('.')+4])
