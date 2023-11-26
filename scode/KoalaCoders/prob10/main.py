import math

def overlapping_volume(a, b, d):
    if d >= a + b:
        return 0

    h = a + b - d
    volume = (1/6) * math.pi * h * (3 * a**2 + 3 * b**2 - h**2)
    return volume



x1, y1, z1, radius1 = map(float, input().split())
x2, y2, z2, radius2 = map(float, input().split())
"""radius1 = float(input())
    radius2 = float(input())"""
distance = math.sqrt((x1-x2)**2+(y1-y2)**2+(z1-z2)**2)
#print(distance)

if radius1 < 0 or radius2 < 0 or distance < 0:
    raise ValueError()


result = overlapping_volume(radius1, radius2, distance)
print(result)
