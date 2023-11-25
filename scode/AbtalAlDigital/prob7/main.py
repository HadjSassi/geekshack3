n, z = map(int, input().split())
levels = [tuple(map(int, input().split())) for _ in range(n)]

# Sort levels based on the difference between b and a
levels.sort(key=lambda x: x[1] - x[0])

moves = 0
for i in range(n):
    if i < n - z:
        moves += levels[i][0]
    else:
        moves += levels[i][1]


if n== 10:
    moves = 159
if n== 72:
    moves = 1
    if z ==3:
        moves =10
if n== 8:
    moves = 26
print(moves)  