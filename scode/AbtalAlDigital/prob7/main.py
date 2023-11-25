n, z = map(int, input().split())
levels = [list(map(int, input().split())) for _ in range(n)]

# Sort levels based on the difference between b and a
levels.sort(key=lambda x: x[0] - x[1])

moves = 0

for i in range(n):
    if levels[i][1] < levels[i][0] and z > 0:
        moves += levels[i][1]
        z -= 1
    else:
        moves += levels[i][0]

print(moves)