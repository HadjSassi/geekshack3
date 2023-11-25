n, z = map(int, input().split())
levels = [tuple(map(int, input().split())) for _ in range(n)]

levels.sort(key=lambda x: (x[1], x[0]))

stars_collected = 0
moves_required = 0

for i in range(n - 1, -1, -1):
    if stars_collected >= z:
        break

    if levels[i][0] < levels[i][1]:
        stars_collected += 2
    else:
        stars_collected += 1

    moves_required += 1

print(moves_required)