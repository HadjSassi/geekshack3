import math

def overlap_volume(world1, world2):
    center1, radius1 = world1
    center2, radius2 = world2

    distance = math.sqrt((center2[0] - center1[0])**2 + (center2[1] - center1[1])**2 + (center2[2] - center1[2])**2)

    if distance >= radius1 + radius2:
        return 0  

    r1_sq = radius1**2
    r2_sq = radius2**2
    d_sq = distance**2

    term1 = r1_sq * math.acos((d_sq + r1_sq - r2_sq) / (2 * distance * radius1))
    term2 = r2_sq * math.acos((d_sq + r2_sq - r1_sq) / (2 * distance * radius2))
    term3 = 0.5 * math.sqrt((-distance + radius1 + radius2) * (distance + radius1 - radius2) * (distance - radius1 + radius2) * (distance + radius1 + radius2))

    overlap_volume = term1 + term2 - term3

    return overlap_volume

L1 = list(map(float,input().split()))
world1 = ((L1[0], L1[1], L1[2]), L1[3])  

L1 = list(map(float,input().split()))
world2 = ((L1[0], L1[1], L1[2]), L1[3])

result = overlap_volume(world1, world2)
print("{:.3f}".format(result))
