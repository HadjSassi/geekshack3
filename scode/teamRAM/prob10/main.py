import math

def shared_volume(x1, y1, z1, r1, x2, y2, z2, r2):
    d = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2)
    if d >= r1 + r2:
        return 0
    if d <= abs(r1 - r2) and r1 >= r2:
        return (4 / 3) * math.pi * (r2 ** 3)
    if d <= abs(r1 - r2) and r2 >= r1:
        return (4 / 3) * math.pi * (r1 ** 3)
    h1 = (r1 ** 2 - r2 ** 2 + d ** 2) / (2 * d)
    h2 = d - h1
    v1 = (math.pi * h1 ** 2 * (3 * r1 - h1))/ 3
    v2 = (math.pi  * h2 ** 2 * (3 * r2 - h2))/3
    #v1=((math.pi*h1)/6)*(3*r1**2 + h1**2)
    #v2 = ((math.pi * h2) / 6) * (3 * r2 ** 2 + h2 ** 2)

    return v1 + v2

x1, y1, z1, r1 = map(float, input().split())
x2, y2, z2, r2 = map(float, input().split())

shared_vol = shared_volume(x1, y1, z1, r1, x2, y2, z2, r2)
print(shared_vol)
