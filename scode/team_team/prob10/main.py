import math

def v(a, b, c):
    if c >= a + b:
        return 0

    h = a + b - c
    v0 = (1/6) * math.pi * h * (3 * a**2 + 3 * b**2 - h**2)
    return v0



x1, y1, z1, r1 = map(float, input().split())
x2, y2, z2, r2 = map(float, input().split())

distance = math.sqrt((x1-x2)**2+(y1-y2)**2+(z1-z2)**2)
#print(distance)






print(v(r1, r2, distance))