n, z = map(int, input().split())
levels = [list(map(int, input().split())) for _ in range(n)]

levels.sort(key=lambda x: x[1] - x[0])

moves = 0

for i in range(n):
    if z > 0:
        moves += levels[i][0]
        z -= 1
    else:
        moves += levels[i][1]
        z -= 2
print(moves)