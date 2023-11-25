n, z = map(int, input().split())
levels = [tuple(map(int, input().split())) for _ in range(n)]

# Sort levels based on the difference between b and a in ascending order
levels.sort(key=lambda x: (x[1] - x[0], x[0]))

moves = 0

for i in range(min(z,n)):
    moves += levels[i][0]

for i in range(z, n):
    moves += min(levels[i][0], levels[i][1])

print(moves)