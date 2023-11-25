import math

def overlap_volume(world1, world2):
    x1, y1, z1, r1 = world1
    x2, y2, z2, r2 = world2

    distance = math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2)

    if distance >= r1 + r2:
        # No overlap, spheres are separate
        return 0

    if distance <= abs(r1 - r2):
        # One sphere is entirely within the other
        return (4/3) * math.pi * min(r1, r2)**3

    a = (r1**2 - r2**2 + distance**2) / (2 * distance)
    b = distance - a

    volume1 = (1/3) * math.pi * (3 * r1 - a)**2 * (a + r1 - 3 * r2)
    volume2 = (1/3) * math.pi * (3 * r2 - b)**2 * (b + r2 - 3 * r1)

    return volume1 + volume2

# Input
world1 = list(map(int, input().split()))
world2 = list(map(int, input().split()))

# Output
result = overlap_volume(world1, world2)
print(f"{result:.3f}")
