l, h, x, y, vx, vy, K = map(int, input().split())

for _ in range(K):
    tx = (l - x) / abs(vx) if vx > 0 else x / abs(vx)
    ty = (h - y) / abs(vy) if vy > 0 else y / abs(vy)

    t = min(tx, ty)
    x += t * vx
    y += t * vy

    if tx < ty:
        vx *= -1
    else:
        vy *= -1

# Ensure the final coordinates are within bounds
x = max(0, min(x, l))
y = max(0, min(y, h))

# Print the final coordinates as integers
print(int(x), int(y))
