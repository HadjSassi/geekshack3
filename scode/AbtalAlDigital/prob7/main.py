n, z = map(int, input().split())
levels = []

for _ in range(n):
    a, b = map(int, input().split())
    levels.append((a, b))

# Sort levels based on the difference between b and a
levels.sort(key=lambda x: x[1] - x[0])

moves = 0

for i in range(z):
    moves += levels[i][0]

for i in range(z, n):
    moves += levels[i][1]

print(moves)