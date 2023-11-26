n, z = map(int, input().split())

levels = []
for _ in range(n):
    a, b = map(int, input().split())
    levels.append((a, b))

levels.sort(key=lambda x: x[1] - x[0], reverse=True)

moves = 0
stars = 0

for level in levels:
    if stars < z:
        moves += 1
        stars += level[0]

    if stars >= z:
        break

print(moves)
