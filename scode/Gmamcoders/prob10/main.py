import math

def volumedecollision(x1, y1, z1, r1, x2, y2, z2, r2):
    d = math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2)

    if d >= r1 + r2:
        return 0

    elif d + min(r1, r2) <= max(r1, r2):
        return (4/3) * math.pi * min(r1, r2)**3

    else:

        h = 0.5 * (1/d) * math.sqrt((r1 + r2 - d) * (r1 - r2 + d) * (-r1 + r2 + d))

        v = (math.pi / 3) * h**2 * (3 * r1 - h + 3 * r2 - h)
        return v

x1, y1, z1, r1 = map(float, input().split())
x2, y2, z2, r2 = map(float, input().split())


V = volumedecollision(x1, y1, z1, r1, x2, y2, z2, r2)
print(f"{V:.3f}")